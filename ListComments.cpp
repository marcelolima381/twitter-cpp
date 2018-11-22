//
// Created by pedro on 11/11/18.
//
#define OPCAO_INVALIDA 400


#include <iostream>
#include "ListComments.hpp"
#include "Feed.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include <climits> // for INT_MAX limits

/**
 * Construtor
 * @param tweet
 */
ListComments::ListComments(TAD::Tweet *tweet) : AbstractInterface("Comentarios") {
	this->tweet = tweet;
}

/**
 * @brief Exibe o menu de opções do Comentário de um Tweet
 */
void ListComments::exibir() {

	int opcao;
	do {
		exibirComentarios();
		std::cout << "Escolha a opção" << std::endl << "1 - Comentar" << std::endl << "0 - Sair" << std::endl;
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
 * @brief Processa a entrada do menu
 * @param opcao
 */
void ListComments::processarEntrada(int &opcao) {
	system("clear");
	switch (opcao) {
		case 1:comentar();
			break;
		case 0:return;
		default:std::__throw_bad_function_call();
	}
}

/**
 * @brief Lê um novo comentário
 */
void ListComments::comentar() {
	std::string texto;

	auto *comments = new TAD::Comments();
	std::cout << "Digite o comentário:" << std::endl;
	std::cin.ignore();
	getline(std::cin, texto);

	comments->inserirComentario(texto, Sessao::Session::getUsuarioLogado()->getId(), this->tweet->getId());
	delete (comments);
}

/**
 * @brief Imprime os comentários do Tweet atual
 */
void ListComments::exibirComentarios() {

	auto *comments = new TAD::Comments();

	std::vector<TAD::Comments> listComments = comments->carregarComments(this->tweet->getId());

	for (auto &listComment : listComments) {
		std::cout << listComment.getUser()->getProfile() + ": " +
			listComment.getDescription() << std::endl;
	}

	delete (comments);
}
