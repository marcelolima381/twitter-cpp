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
void Pesquisa::processarEntrada(int opcao) {
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

	cout << "Digite o que pesquisa:" << std::endl;
	cin.ignore();
	getline(cin, pesquisa);

	auto *user = new Users();

	usuariosPesquisados = user->pesquisarUsuarios(pesquisa);
	exibirUsuariosPesquisados();
}
/**
 * @brief Realiza a pesquisa por uma hastag
 */
void Pesquisa::pesquisarHashTag() {
	std::string pesquisa;

	cout << "Digite o que pesquisa:" << std::endl;
	cin.ignore();
	getline(cin, pesquisa);

	auto *tweet = new Tweet();

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
			cout << "ID: " << setw(3) << left << std::to_string(tweetsPesquisado.getId()) <<
				 "Profile: " << setw(20) << left << tweetsPesquisado.getUser()->getProfile() << std::endl <<
				 "Tweet: " << tweetsPesquisado.getDescription() << std::endl << std::endl;
		}

	} else {
		cout << "Não foram encontrados tweets com a hashtag informada." << std::endl;
	}

}
/**
 * @brief Exibe usuários pesquisados
 */
void Pesquisa::exibirUsuariosPesquisados() {
	if (!usuariosPesquisados.empty()) {
		for (auto &usuariosPesquisado : usuariosPesquisados) {
			cout << "ID: " << setw(3) << left << std::to_string(usuariosPesquisado.getId()) <<
				 "Profile: " << setw(20) << left << usuariosPesquisado.getProfile() <<
				 " Nome: " << setw(30) << left << usuariosPesquisado.getName() << std::endl;
		}
		associarUsuario();
	} else {
		cout << "Não foram encontrados usuários." << std::endl;
	}

}
/**
 * @brief Possibilita um usuário poder seguir outro
 */
void Pesquisa::associarUsuario() {
	int id;

	do {
		cout << std::endl << "Digite o ID do usuário para segui-lo, ou digite 0 para voltar." << std::endl;
		cin >> id;

		if (id != 0) {
			for (auto &usuariosPesquisado : usuariosPesquisados) {
				if (usuariosPesquisado.getId() == id) {
					auto *user = new Users();

					user->seguirUsuario(Session::getUsuarioLogado()->getId(), id);

					cout << "Você agora segue o usuário: " << usuariosPesquisado.getProfile();
					return;
				}
			}
			cout << "ID não encontrado." << std::endl;
		}

	} while (id != 0);
}
