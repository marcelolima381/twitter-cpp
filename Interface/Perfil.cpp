//
// Created by marcelo on 17/11/18.
//

#include "Perfil.hpp"
#include "../TAD/Tweet.hpp"
#include "../Sessao/Session.hpp"
#include "ListComments.hpp"
#include <climits> // for INT_MAX limits

#define AVANCAR 1
#define RETROCEDER 2
#define FEED 3
#define COMENTARIOS 4
#define SAIR 0
#define EDITAR_PERFIL 5
#define VER_SEGUIDORES 6
#define VER_QUEM_EU_SIGO 7
#define OPCAO_INVALIDA 400

namespace Interface {

/**
 * @brief Construtor
 */
Perfil::Perfil() : AbstractInterface("Perfil") {}

/**
 * @brief Exibe o conteúdo do perfil do usuário logado
 */
void Perfil::exibir() {
	int opcao;
//	auto *user = new Users();
	std::cout << "Perfil: " << Sessao::Session::getUsuarioLogado()->getProfile() << std::endl << "Nome: "
			  << Sessao::Session::getUsuarioLogado()->getName() << std::endl << "Cidade: "
			  << Sessao::Session::getUsuarioLogado()->getCity() << std::endl << "Idade: "
			  << Sessao::Session::getUsuarioLogado()->getAge() << std::endl;
	auto *tweet = new TAD::Tweet();
	tweets = tweet->carregarTweetsUsuarioLogado(Sessao::Session::getUsuarioLogado()->getId());
	index = 0;
	do {
		if (tweets.empty()) {
//			std::cout << "Você não tem tweets para exibir" << std::endl;
			std::cout << "Escolha a opção:" << std::endl << "3 - Feed" << std::endl << "5 - Editar perfil"
					<< std::endl << "6 - Ver seguidores" << std::endl << "7 - Ver quem eu sigo" << std::endl;
		} else {
			exibirTweet(tweets.at(this->index));
			std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2 - Retroceder" << std::endl
					  << "3 - Feed" << std::endl << "4 - Ver Comentários" << std::endl << "5 - Editar perfil"
					<< std::endl << "6 - Ver seguidores" << std::endl << "7 - Ver quem eu sigo" << std::endl;
		}
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
		} catch (std::out_of_range &e) {
			std::cout << std::endl << "\033[1;31mErro: " << e.what() << "\033[0m" << std::endl << std::endl;
		}
		if (opcao == FEED) {
			opcao = 0;
		}
	} while (opcao != 0);
}
/**
 * @brief Processa a entrada recebida no menu do Perfil
 * @param opcao
 */
void Perfil::processarEntrada(int opcao) {
	switch (opcao) {
		case AVANCAR:
			system("clear");
			if (tweets.empty()) {
				std::__throw_out_of_range("Você não tem tweets para exibir. Crie um tweet.");
			} else {
				avancarTweet();
			}
			break;

		case RETROCEDER:
			system("clear");
			if (tweets.empty()) {
				std::__throw_out_of_range("Você não tem tweets para exibir. Crie um tweet.");
			} else {
				retrocederTweet();
			}
			break;

		case FEED: system("clear");
			return;

		case COMENTARIOS:
			if (tweets.empty()) {
				system("clear)");
				std::__throw_out_of_range("Você não tem tweets ou comentários para exibir. Crie um tweet.");
			} else {
				entrarComentarios();
			}
			break;

		case EDITAR_PERFIL:editarPerfil();
			break;

		case VER_SEGUIDORES:
			verSeguidores();
			break;
		case VER_QUEM_EU_SIGO:
			verQuemEuSigo();
			break;
		default:std::__throw_invalid_argument("Opção inválida! Digite outra opção.");
	}
}
/**
 *@brief Rebece comentários e mostra os comentários atuais
 */
void Perfil::entrarComentarios() {
	auto *listComments = new ListComments(ObterTweetPeloIndice());
	listComments->exibir();
}
/**
 * @brief Mostra um tweet em determinado índice
 * @return Tweet
 */
TAD::Tweet *Perfil::ObterTweetPeloIndice() {
	return &tweets.at(index);
};
/**
 * @brief Mostra a posição de um tweet, o autor e o texto contido nele
 * @param tweet
 */
void Perfil::exibirTweet(TAD::Tweet tweet) {
	std::cout << "Tweet " + std::to_string((index + 1)) + " de " + std::to_string(tweets.size()) << std::endl;
	std::cout << std::endl << tweet.getUser()->getProfile() << ":" << std::endl;
	std::cout << tweet.getDescription() << std::endl << std::endl;
}
/**
 * @brief Avança para o próximo tweet
 */
void Perfil::avancarTweet() {

	if (this->index + 1 >= tweets.size()) {
		system("clear");
		std::cout << "Não é possível avançar mais." << std::endl;
	} else
		this->index++;
}
/**
 * @brief Retrocede para o tweet anterior
 */
void Perfil::retrocederTweet() {
	if (this->index <= 0) {
		system("clear");
		std::cout << "Não é possível retroceder mais." << std::endl;
	} else
		this->index--;
}
/**
 * @brief Permite o usuário alterar dados em seu perfil
 */
void Perfil::editarPerfil() {
	auto *user = new TAD::Users();
	int opcao;
	std::string nome, cidade, senha;
	int idade;
	std::cout << "Qual dado do perfil você deseja editar?" << std::endl << "1 - Nome" << std::endl << "2 - Cidade"
			  << std::endl << "3 - Idade" << std::endl << "4 - Senha" << std::endl;
	std::cin >> opcao;
	system("clear");
	switch (opcao) {
		case 1:std::cout << "Digite o novo nome" << std::endl;
			std::cin.ignore();
			getline(std::cin, nome);
			user->editarCampo("name", nome);
			Sessao::Session::getUsuarioLogado()->setName(nome);
			break;

		case 2:std::cout << "Digite a nova cidade" << std::endl;
			std::cin.ignore();
			getline(std::cin, cidade);
			user->editarCampo("city", cidade);
			Sessao::Session::getUsuarioLogado()->setCity(cidade);
			break;

		case 3:std::cout << "Digite a nova idade" << std::endl;
			std::cin >> idade;
			user->editarCampo("age", std::to_string(idade));
			Sessao::Session::getUsuarioLogado()->setAge(idade);
			break;

		case 4:std::cout << "Digite a novo senha" << std::endl;
			std::cin.ignore();
			getline(std::cin, senha);
			user->editarCampo("password", senha);
			Sessao::Session::getUsuarioLogado()->setPassword(senha);
			break;

		default: std::__throw_invalid_argument("Opção, inválida!");
	}
}

	void Perfil::verSeguidores() {
		auto *user = new TAD::Users();
		auto listaUsuarios = user->pesquisarSeguidores(Sessao::Session::getUsuarioLogado()->getId());

		system("clear");
		std::cout<<"Seguidores:"<<std::endl;
		for (auto usuariosPesquisado : listaUsuarios) {
			std::cout<<"ID: "<< usuariosPesquisado.getId() << " Nome: "<< usuariosPesquisado.getName() << std::endl;
		}

		int opcao = 0;

		do {
			std::cout<< std::endl<<"Digite o ID de um usuário para remover o seguidor ou digite 0 para voltar."<<std::endl;
			std::cin >> opcao;

			if(opcao!=0)
			{
				bool achou = false;
				for (auto usuariosPesquisado : listaUsuarios) {
					if(usuariosPesquisado.getId()==opcao)
					{
						achou = true;
						user->excluirSeguirUsuario(opcao,Sessao::Session::getUsuarioLogado()->getId());
						std::cout<<"Você deixou de seguir o usuário "+ usuariosPesquisado.getName();

						listaUsuarios = user->pesquisarSeguidores(Sessao::Session::getUsuarioLogado()->getId());

						for (auto usuariosPesquisado2 : listaUsuarios) {
							std::cout<< std::endl<<"Seguidores:"<<std::endl;
							std::cout<<"ID: "<< usuariosPesquisado2.getId() << " Nome: "<< usuariosPesquisado2.getName() << std::endl;
						}
					}
				}
				if(!achou)
					std::cout<< std::endl<<"ID de usuário inválido."<<std::endl;
			}

		} while (opcao != 0);
	}

	void Perfil::verQuemEuSigo() {
		auto *user = new TAD::Users();
		auto listaUsuarios = user->pesquisarQuemUsuarioSegue(Sessao::Session::getUsuarioLogado()->getId());

		system("clear");
		std::cout<<"Quem eu sigo:"<<std::endl;
		for (auto usuariosPesquisado : listaUsuarios) {
			std::cout<<"ID: "<< usuariosPesquisado.getId() << " Nome: "<< usuariosPesquisado.getName() << std::endl;
		}


		int opcao = 0;

		do {
			std::cout<< std::endl<<"Digite o ID de um usuário para deixar de seguir ou digite 0 para voltar."<<std::endl;
			std::cin >> opcao;

			if(opcao!=0)
			{
				bool achou = false;
				for (auto usuariosPesquisado : listaUsuarios) {
					if(usuariosPesquisado.getId()==opcao)
					{
						achou = true;
						user->excluirSeguirUsuario(Sessao::Session::getUsuarioLogado()->getId(),opcao);
						std::cout<<"Você não segue mais o usuário "+ usuariosPesquisado.getName();

						listaUsuarios = user->pesquisarQuemUsuarioSegue(Sessao::Session::getUsuarioLogado()->getId());

						std::cout<< std::endl<<"Quem eu sigo:"<<std::endl;
						for (auto usuariosPesquisado2 : listaUsuarios) {
							std::cout<<"ID: "<< usuariosPesquisado2.getId() << " Nome: "<< usuariosPesquisado2.getName() << std::endl;
						}
					}
				}
				if(!achou)
					std::cout<< std::endl<<"ID de usuário inválido."<<std::endl;
			}

		} while (opcao != 0);
	}

}