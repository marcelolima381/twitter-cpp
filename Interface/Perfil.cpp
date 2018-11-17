//
// Created by marcelo on 17/11/18.
//

#include "Perfil.hpp"
#include "../TAD/Tweet.hpp"
#include "../Sessao/Session.hpp"


Perfil::Perfil() : AbstractInterface("Perfil") {}

void Perfil::exibir() {
    int opcao;
    Tweet *tweet = new Tweet();
    tweets = tweet->carregarTweetsUsuariosSeguidos(Session::getUsuarioLogado()->getId());
    index = 0;
//    exibirTweet(tweets.at(index));
    do {
        std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2- Retroceder" << std::endl
                  << "3 - Meu Perfil" << std::endl << "4 - Ver Comentários" << std::endl << "0 - Sair" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
    } while (opcao != 0);
}

void Perfil::processarEntrada(int opcao) {

}
