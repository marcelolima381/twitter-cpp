//
// Created by pedro on 17/11/18.
//

#include "Pesquisa.hpp"
#include "../TAD/Tweet.hpp"
#include "../Sessao/Session.hpp"
#include "ListComments.hpp"
#include <iomanip>

#define HASHTAG 1
#define USUARIOS 2
#define SAIR 0
/**
 * @brief Construtor
 */
Pesquisa::Pesquisa() : AbstractInterface("Pesquisa") {}
/**
 * Exibe um menu para escolha de modo de pesquisa
 */
void Pesquisa::exibir() {

	int opcao = 0;
	do {
		std::cout << std::endl << "Escolha a opção:" << std::endl << "1 - Pesquisar hashtag" << std::endl
				  << "2 - Pesquisar Usuários"
				  << std::endl << "0 - Sair" << std::endl;
		std::cin >> opcao;
		this->processarEntrada(opcao);
		system("clear");
	} while (opcao != 0);
}
/**
 * @brief Processa a entrada recebida pelo menu de modo de pesquisa
 * @param opcao
 */
void Pesquisa::processarEntrada(int &opcao) {
	switch (opcao) {
		case HASHTAG:pesquisarHashTag();
			break;

		case USUARIOS:pesquisarUsuario();
			break;

		case SAIR:break;

		default:std::cout << "Opção inválida!. Digite outra opção." << std::endl;
	}
}
/**
 * @brief Realiza a pesquisa por um usuário
 */
void Pesquisa::pesquisarUsuario() {
	std::string pesquisa;

	std::cout << "Digite o que pesquisa:" << std::endl;
	std::cin.ignore();
	getline(std::cin, pesquisa);

	auto *user = new TAD::Users();

	usuariosPesquisados = user->pesquisarUsuarios(pesquisa);
	exibirUsuariosPesquisados();
}
/**
 * @brief Realiza a pesquisa por uma hastag
 */
void Pesquisa::pesquisarHashTag() {
	std::string pesquisa;

	std::cout << "Digite o que pesquisa:" << std::endl;
	std::cin.ignore();
	getline(std::cin, pesquisa);

	auto *tweet = new TAD::Tweet();

	if (pesquisa[0] != '#')
		pesquisa = '#' + pesquisa;

	tweetsPesquisados = tweet->pesquisarPorHashtag(pesquisa);
	exibirTweetsPesquisados();
}

/**
 * @brief Exibe tweets pesquisados
 */
void Pesquisa::exibirTweetsPesquisados() {
	if (!tweetsPesquisados.empty()) {
		for (auto &tweetsPesquisado : tweetsPesquisados) {
			std::cout << "ID: " << std::setw(3) << std::left << std::to_string(tweetsPesquisado.getId()) <<
				 "Profile: " << std::setw(20) << std::left << tweetsPesquisado.getUser()->getProfile() << std::endl <<
				 "Tweet: " << tweetsPesquisado.getDescription() << std::endl << std::endl;
		}

	} else {
		std::cout << "Não foram encontrados tweets com a hashtag informada." << std::endl;
	}

}
/**
 * @brief Exibe usuários pesquisados
 */
void Pesquisa::exibirUsuariosPesquisados() {
	if (!usuariosPesquisados.empty()) {
		for (auto &usuariosPesquisado : usuariosPesquisados) {
			std::cout << "ID: " << std::setw(3) << std::left << std::to_string(usuariosPesquisado.getId()) <<
				 "Profile: " << std::setw(20) << std::left << usuariosPesquisado.getProfile() <<
				 " Nome: " << std::setw(30) << std::left << usuariosPesquisado.getName() << std::endl;
		}
		associarUsuario();
	} else {
		std::cout << "Não foram encontrados usuários." << std::endl;
	}

}
/**
 * @brief Possibilita um usuário poder seguir outro
 */
void Pesquisa::associarUsuario() {
	int id;

	do {
		std::cout << std::endl << "Digite o ID do usuário para segui-lo, ou digite 0 para voltar." << std::endl;
		std::cin >> id;

		if (id != 0) {
			for (auto &usuariosPesquisado : usuariosPesquisados) {
				if (usuariosPesquisado.getId() == id) {
					auto *user = new TAD::Users();

					user->seguirUsuario(Sessao::Session::getUsuarioLogado()->getId(), id);

					std::cout << "Você agora segue o usuário: " << usuariosPesquisado.getProfile();
					return;
				}
			}
			std::cout << "ID não encontrado." << std::endl;
		}

	} while (id != 0);
}
