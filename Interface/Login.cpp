//
// Created by marcelo on 02/11/18.
//

#define OPCAO_INVALIDA 400
#define LOGAR 1
#define CRIAR_CONTA 2
#define SAIR 0

#include <iostream>
#include "Login.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include "Feed.hpp"
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <climits> // for INT_MAX limits

namespace Interface {

/**
 * Construtor
 */
Login::Login() : AbstractInterface("Twitter") {}

/**
 * @brief Auxilia na manipulação de caracteres recebidos como entrada na senha do usuário
 * @return int
 */
int getch() {
	int ch;
	struct termios t_old{}, t_new{};

	tcgetattr(STDIN_FILENO, &t_old);
	t_new = t_old;
	t_new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
	return ch;
}

/**
 * @brief Retorna a string correspondente à senha do usuário e faz com que
 * suas entradas apareçam como '*' na tela
 * @param prompt, show_asterisk
 * @return string
 */
std::string getpass(const char *prompt, bool show_asterisk = true) {
	const char BACKSPACE = 127;
	const char RETURN = 10;

	std::string password;
	unsigned char ch = 0;

	std::cout << prompt;

	while ((ch = getch()) != RETURN) {
		if (ch == BACKSPACE) {
			if (password.length() != 0) {
				if (show_asterisk)
					std::cout << "\b \b";
				password.resize(password.length() - 1);
			}
		} else {
			password += ch;
			if (show_asterisk)
				std::cout << '*';
		}
	}
	std::cout << std::endl;
	return password;
}

/**
 * @brief Exibe o menu de login
 */
void Login::exibir() {
	int opcao;
	do {
		std::cout << "Escolha a opção" << std::endl << "1 - Login" << std::endl << "2 - Criar conta" << std::endl
				  << "0 - Sair" << std::endl;
		try {
			std::cin >> opcao;
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				opcao = OPCAO_INVALIDA;
				std::__throw_bad_function_call();
			}
			this->processarEntrada(opcao);
		} catch (std::invalid_argument &e) {
			system("clear");
			std::cout << std::endl << "\033[1;31mArgumento inválido: " << e.what() << std::endl
					  << "Tente novamente.\033[0m" << std::endl << std::endl;
		} catch (std::bad_function_call &e) {
			system("clear");
			std::cout << std::endl << "\033[1;33mErro. Escolha uma opção válida do menu.\033[0m" << std::endl
					  << std::endl;
		}
	} while (opcao != 0);
}
/**
 * @brief Processa a entrada do menu de login
 * @param opcao
 */
void Login::processarEntrada(int opcao) {
//    std::cout << opcao << std::endl;
	switch (opcao) {
		case LOGAR:logar();
			break;

		case CRIAR_CONTA:criarConta();
			break;

		case SAIR: break;

		default:std::__throw_invalid_argument("Digite outra opção.");
	}
}
/**
 * @brief Lê os dados de login, encaminha os dados para validação no banco de dados e procede de acordo
 */
void Login::logar() {
	std::string conta, senha;
	std::cout << "Login: ";
	std::cin >> conta;
	std::cin.ignore();
	senha = getpass("Senha: ", true);
	auto *user = new TAD::Users();

	std::cout << "Validando login..." << std::endl;
	bool flag = user->validarLogin(conta, senha);
	if (flag) {
		system("clear");
		Sessao::Session::setUsuarioLogado(user);
		auto *feed = new Feed();
		feed->exibir();
	} else {
		std::__throw_invalid_argument("Login e/ou senha inválidos");
	}

}
/**
 * @brief Realiza a criação de uma nova conta de usuário
 */
void Login::criarConta() {
	std::string account, password, profile, name, city, retornoCriacao;
	int age;

	std::cout << "Insira os dados da sua nova conta." << std::endl;
	std::cout << "Apelido: ";
	std::cin.ignore();
	getline(std::cin, profile);
	password = getpass("Senha: ", true);
	std::cout << "Email: ";
//	cin.ignore();
	getline(std::cin, account);
	std::cout << "Nome: ";
//	cin.ignore();
	getline(std::cin, name);
	std::cout << "Idade: ";
	std::cin.ignore();
	std::cin >> age;
	std::cout << "Cidade: ";
	std::cin.ignore();
	getline(std::cin, city);

	auto *user = new TAD::Users();

	retornoCriacao = user->criarConta(account, password, profile, name, city, age);

	std::cout << "Usuario " + profile + " criado!" << std::endl;
}

}