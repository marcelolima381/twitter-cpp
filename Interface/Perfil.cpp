//
// Created by marcelo on 17/11/18.
//

#include "Perfil.hpp"
#include "../TAD/Tweet.hpp"
#include "../Sessao/Session.hpp"
#include "ListComments.hpp"

#define AVANCAR 1
#define RETROCEDER 2
#define FEED 3
#define COMENTARIOS 4
#define SAIR 0

Perfil::Perfil() : AbstractInterface("Perfil") {}

void Perfil::exibir() {
    int opcao;
    Tweet *tweet = new Tweet();
    tweets = tweet->carregarTweetsUsuarioLogado(Session::getUsuarioLogado()->getId());
    index = 0;
    exibirTweet(tweets.at(index));
    do {
        std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2- Retroceder" << std::endl
                  << "3 - Feed" << std::endl << "4 - Ver Comentários" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
    } while (opcao != 0);
}

void Perfil::processarEntrada(int opcao) {
    Tweet *tweet = new Tweet();
    switch (opcao) {
        case AVANCAR:
            tweet->avancarTweet(index);
            break;

        case RETROCEDER:
            tweet->retrocederTweet(index);
            break;

        case FEED:
            break;

        case COMENTARIOS:
            entrarComentarios();
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Perfil::entrarComentarios() {
    ListComments *listComments = new ListComments(ObterTweetPeloIndice());
    listComments->exibir();
}

Tweet* Perfil::ObterTweetPeloIndice()
{
    return &tweets.at(index);
};

void Perfil::exibirTweet(Tweet tweet) {
    std::cout << "Funcionou!" << std::endl;
    std::cout << tweet.getUser()->getProfile() << std::endl;
    std::cout << tweet.getDescription() << std::endl;
}