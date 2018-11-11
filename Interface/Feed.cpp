//
// Created by marcelo on 02/11/18.
//

#include "Feed.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include "../TAD/Tweet.hpp"
#include <vector>

#define AVANCAR 1
#define RETROCEDER 2
#define PERFIL 3
#define SAIR 0

Feed::Feed() : AbstractInterface("Feed") {}

void Feed::exibir() {
    int opcao;
    Tweet *tweet = new Tweet();
    tweets = tweet->carregarTweets(Session::getUsuarioLogado()->getId());
    index = 0;
    exibirTweet(tweets.at(index));
    do {
        std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2- Retroceder" << std::endl
                  << "3 - Meu Perfil" << std::endl << "0 - Sair" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
    } while (opcao != 0);
}

void Feed::processarEntrada(int opcao) {
    Tweet *tweet = new Tweet();
    switch (opcao) {
        case AVANCAR:
            tweet->avancarTweet(index);
            break;

        case RETROCEDER:
            tweet->retrocederTweet(index);
            break;

        case PERFIL:
//            entrarPerfil();
            break;

        case SAIR:
//            sair();
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Feed::exibirTweet(Tweet tweet) {
    std::cout << "Funcionou!" << std::endl;
}


