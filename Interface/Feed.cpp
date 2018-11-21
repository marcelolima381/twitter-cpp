#include "Feed.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include "../TAD/Tweet.hpp"
#include "Perfil.hpp"
#include "Pesquisa.hpp"
#include <vector>
#include <climits> // for INT_MAX limits

#define AVANCAR 1
#define RETROCEDER 2
#define PERFIL 3
#define COMENTARIOS 4
#define TWEETAR 5
#define PESQUISAR 6
#define CURTIR 7
#define VER_CURTIDAS 8
#define SAIR 0
#define OPCAO_INVALIDA 400

/**
 * Construtor
 */
Feed::Feed() : AbstractInterface("Feed") {}

/**
 * @brief Exibe o menu de opções do Feed
 */
void Feed::exibir() {
	int opcao = 0;
	Tweet *tweet = new Tweet();
	cout << "Carregando..." << std::endl;
	tweets = tweet->carregarTweetsUsuariosSeguidos(Session::getUsuarioLogado()->getId());
	this->index = 0;
	system("clear");
	std::cout << std::endl << "\033[1;36mOlá, " << Session::getUsuarioLogado()->getName() << "\033[0m" << std::endl
			  << std::endl;
	do {
		if (tweets.empty()) {
			std::cout << "Escolha a opção:" << std::endl << "3 - Meu Perfil" << std::endl << "5 - Tweetar" <<
					  std::endl << "6 - Pesquisar" << std::endl << "0 - Sair" << std::endl;
		} else {
			exibirTweet(tweets.at(this->index));
			std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2 - Retroceder" << std::endl
					  << "3 - Meu Perfil" << std::endl << "4 - Ver Comentários" << std::endl << "5 - Tweetar" <<
					  std::endl << "6 - Pesquisar" << std::endl << "7 - Curtir" << std::endl << "8 - Ver quem curtiu"
					  << std::endl << "0 - Sair" << std::endl;
		}
		try {
			std::cin >> opcao;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				opcao = OPCAO_INVALIDA;
				__throw_bad_function_call();
			}
			this->processarEntrada(opcao);
		} catch (invalid_argument &e) {
			system("clear");
			std::cout << std::endl << "\033[1;31mArgumento inválido: " << e.what() << std::endl
					  << "Tente novamente.\033[0m" << std::endl << std::endl;
		} catch (bad_function_call &e) {
			system("clear");
			std::cout << std::endl << "\033[1;33mErro. Escolha uma opção válida do menu.\033[0m" << std::endl
					  << std::endl;
		} catch (out_of_range &e) {
			std::cout << std::endl << "\033[1;31mErro: " << e.what() << "\033[0m" << std::endl << std::endl;
		}
	} while (opcao != 0);
}

/**
 * @brief Processa a entrada do menu
 * @param opcao
 */
void Feed::processarEntrada(int opcao) {
	vector<Users> users;
	switch (opcao) {
		case AVANCAR:
			if (tweets.empty()) {
				system("clear");
				__throw_out_of_range("Você não tem tweets para exibir. Tente seguir alguém.");
			} else {
				avancarTweet();
			}
			break;

		case RETROCEDER:
			if (tweets.empty()) {
				system("clear");
				__throw_out_of_range("Você não tem tweets para exibir. Tente seguir alguém.");
			} else {
				retrocederTweet();
			}
			break;

		case PERFIL:entrarPerfil();
			break;

		case COMENTARIOS:
			if (tweets.empty()) {
				system("clear");
				__throw_out_of_range("Você não tem tweets ou comentários para exibir. Tente seguir alguém.");
			} else {
				entrarComentarios();
			}
			break;

		case TWEETAR:tweetar();
			break;

		case PESQUISAR:entrarPesquisa();
			break;

		case CURTIR:
			if (tweets.empty()) {
				system("clear");
				__throw_out_of_range("Você não tem tweets para exibir ou curtir. Tente seguir alguém.");
			} else {
				ObterTweetPeloIndice()->curtirTweet(ObterTweetPeloIndice()->getId(),
													Session::getUsuarioLogado()->getId());
				std::cout << "Tweet curtido com sucesso!" << std::endl;
			}
			break;

		case VER_CURTIDAS:
			if (tweets.empty()) {
				system("clear");
				__throw_out_of_range("Você não tem tweets para exibir ou curtir. Tente seguir alguém.");
			} else {
				users = ObterTweetPeloIndice()->verCurtidas(ObterTweetPeloIndice()->getId());
				for (auto &user : users) {
					std::cout << "Perfil: " << user.getProfile() << std::endl << "Nome: " << user.getName()
							  << std::endl << std::endl;
				}
			}

			break;

		case 0:
			system("clear");
			std::cout << std::endl;
			break;

		default:__throw_invalid_argument("Digite outra opção.");
	}
}

/**
 * @brief Manipula os comentários de um Tweet. Caso não haja um Tweet, uma mensagem é exibida.
 */
void Feed::entrarComentarios() {

	if (tweets.size() == 0) {
		cout << "Você não tem tweets a serem exibidos.";
	} else {
		ListComments *listComments = new ListComments(ObterTweetPeloIndice());
		listComments->exibir();
	}
}

/**
 * @brief Os Tweets são exibidos um a um. O controle de navegação entre os Tweets é feito por um índice.
 *        Através desse índice a função retorna o respectivo Tweet
 * @return Tweet
 */
Tweet *Feed::ObterTweetPeloIndice() {
	return &tweets.at(index);
};

/**
 * @brief Responsável por imprimir os Tweets no Feed do usuário
 * @param tweet
 */
void Feed::exibirTweet(Tweet tweet) {
	std::cout << "Tweet " + std::to_string((index + 1)) + " de " + std::to_string(tweets.size()) << std::endl;
	std::cout << std::endl << tweet.getUser()->getProfile() << ":" << std::endl;
	std::cout << tweet.getDescription() << std::endl << std::endl;
}

/**
 * @brief Faz a transição de interface do Feed para o Perfil
 */
void Feed::entrarPerfil() {
	Perfil *perfil = new Perfil();
	perfil->exibir();
}

/**
 * @brief Faz a transição de interface do Feed para a Pesquisa
 */
void Feed::entrarPesquisa() {
	Pesquisa *pesquisa = new Pesquisa();
	pesquisa->exibir();
}

/**
 * @brief Avança um Tweet pelo sistema de índice
 */
void Feed::avancarTweet() {

	if (this->index + 1 >= tweets.size()) {
		system("clear");
		std::cout << "Não é possível avançar mais." << std::endl;
	} else
		this->index++;
}

/**
 * @brief Retrocede um Tweet pelo sistema de índice
 */
void Feed::retrocederTweet() {
	if (this->index <= 0) {
		system("clear");
		std::cout << "Não é possível retroceder mais." << std::endl;
	} else
		this->index--;
}

/**
 * @brief Lê um novo tweet
 */
void Feed::tweetar() {
	string texto;
	system("clear");
	std::cout << "Escreva o tweet: " << std::endl;
	cin.ignore();
	getline(cin, texto);
	Tweet *tweet = new Tweet();
	tweet->criarTweet(texto, Session::getUsuarioLogado()->getId());
}




