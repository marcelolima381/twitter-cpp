//
// Created by marcelo on 02/11/18.
//

#include <iostream>
#include "Login.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include "Feed.hpp"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

Login::Login() : AbstractInterface("Twitter") {}

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string getpass(const char *prompt, bool show_asterisk = true) {
    const char BACKSPACE = 127;
    const char RETURN = 10;

    string password;
    unsigned char ch = 0;

    std::cout << prompt;

    while ((ch = getch()) != RETURN) {
        if (ch == BACKSPACE) {
            if (password.length() != 0) {
                if (show_asterisk)
                    cout << "\b \b";
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


void Login::exibir() {
    int opcao;
    do {
        std::cout << "Escolha a opção" << std::endl << "1 - Login" << std::endl << "2 - Criar conta" << std::endl
                  << "0 - Sair" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        std::cout << "Coe" << std::endl;
        system("clear");
    } while (opcao != 0);
}

void Login::processarEntrada(int opcao) {
    switch (opcao) {
        case 1:
            logar();
            break;

        case 2:
            criarConta();
            break;

        case 0:
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Login::logar() {
    std::string conta, senha;
    std::cout << "Login: ";
    std::cin >> conta;
    cin.ignore();
    senha = getpass("Senha: ",true);
    Users *user = new Users();

    cout << "Validando login..." << std::endl;
    bool flag = user->validarLogin(conta, senha);
    if (flag) {
        Session::setUsuarioLogado(user);
        Feed *feed = new Feed();
        feed->exibir();
    } else {
        std::cout << "Login ou senha inválido." << endl;
    }


}

void Login::criarConta() {
    std::string account, password, profile, name, city, retornoCriacao;
    int age;

    std::cout << "Insira os dados da sua nova conta." << std::endl;
    std::cout << "Apelido: ";
    cin.ignore();
    getline(cin, profile);
    std::cout << "Senha: ";
    cin.ignore();
    std::cin >> password;
    std::cout << "Email: ";
    cin.ignore();
    std::cin >> account;
    std::cout << "Nome: ";
    cin.ignore();
    getline(cin, name);
    std::cout << "Idade: ";
    cin.ignore();
    std::cin >> age;
    std::cout << "Cidade: ";
    cin.ignore();
    getline(cin, city);

    Users *user = new Users();

    retornoCriacao = user->criarConta(account, password, profile, name, city, age);

    cout << "Usuario " + profile + " criado!" << std::endl;
}

void Login::redirecionarParaFeed() {

}
