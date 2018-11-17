//
// Created by marcelo on 02/11/18.
//

#include "Feed.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include "../TAD/Tweet.hpp"
#include "Perfil.hpp"
#include <vector>

#define AVANCAR 1
#define RETROCEDER 2
#define PERFIL 3
#define COMENTARIOS 4
#define TWEETAR 5
#define SAIR 0

Feed::Feed() : AbstractInterface("Feed") {}

void Feed::exibir() {
    int opcao;
    Tweet *tweet = new Tweet();
    cout << "Carregando..." << std::endl;
    tweets = tweet->carregarTweetsUsuariosSeguidos(Session::getUsuarioLogado()->getId());
    this->index = 0;

    do {
        if (tweets.size() == 0) {
            std::cout << "Escolha a opção:" << std::endl << "3 - Meu Perfil" << std::endl << "5 - Tweetar" <<
                      std::endl << "6 - Pesquisar" << std::endl << "0 - Sair" << std::endl;
        } else {
            exibirTweet(tweets.at(this->index));
            std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2- Retroceder" << std::endl
                      << "3 - Meu Perfil" << std::endl << "4 - Ver Comentários" << std::endl << "5 - Tweetar" <<
                      std::endl << "6 - Pesquisar" << std::endl << "0 - Sair" << std::endl;
        }
        std::cin >> opcao;
        system("clear");
        this->processarEntrada(opcao);
    } while (opcao != 0);
}

void Feed::processarEntrada(int opcao) {

    switch (opcao) {
        case AVANCAR:
            if (tweets.size() == 0) {
                std::cout << "Opção inválida. Você não tem tweets para exibir. Tente seguir alguém." << std::endl;
            } else {
                avancarTweet();
            }
            break;

        case RETROCEDER:
            if (tweets.size() == 0) {
                std::cout << "Opção inválida. Você não tem tweets para exibir. Tente seguir alguém." << std::endl;
            } else {
                retrocederTweet();
            }
            break;

        case PERFIL:
            entrarPerfil();
            break;

        case COMENTARIOS:
            if (tweets.size() == 0) {
                std::cout << "Opção inválida. Você não tem tweets para exibir. Tente seguir alguém." << std::endl;
            } else {
                entrarComentarios();
            }
            break;

        case TWEETAR:
            entrarComentarios();
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Feed::entrarComentarios() {

    if (tweets.size() == 0) {
        cout << "Você não tem tweets a serem exibidos.";
    } else {
        ListComments *listComments = new ListComments(ObterTweetPeloIndice());
        listComments->exibir();
    }
}

Tweet *Feed::ObterTweetPeloIndice() {
    return &tweets.at(index);
};

void Feed::exibirTweet(Tweet tweet) {
    std::cout << "Tweet " + std::to_string((index + 1)) + " de " + std::to_string(tweets.size()) << std::endl;
    std::cout << std::endl << tweet.getUser()->getProfile() << ":" << std::endl;
    std::cout << tweet.getDescription() << std::endl << std::endl;
}

bool Feed::entrarPerfil() {
    Perfil *perfil = new Perfil();
    perfil->exibir();
}

void Feed::avancarTweet() {

    if (this->index + 1 >= tweets.size()) {
        system("clear");
        std::cout << "Não é possível avançar mais." << std::endl;
    } else
        this->index++;
}

void Feed::retrocederTweet() {
    if (this->index <= 0) {
        system("clear");
        std::cout << "Não é possível retroceder mais." << std::endl;
    } else
        this->index--;
}



