//
// Created by pedro on 17/11/18.
//

#include "Pesquisa.hpp"
#include "../TAD/Tweet.hpp"
#include "../Sessao/Session.hpp"
#include "ListComments.hpp"

#define HASHTAG 1
#define USUARIOS 2
#define SAIR 0

Pesquisa::Pesquisa() : AbstractInterface("Pesquisa") {}

void Pesquisa::exibir() {

    int opcao=0;
    do {
        std::cout << std::endl << "Escolha a opção:" << std::endl << "1 - Pesquisar hashtag" << std::endl << "2 - Pesquisar Usuários"
        << std::endl << "0 - Sair" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
    } while (opcao != 0);
}

void Pesquisa::processarEntrada(int opcao) {

    switch (opcao) {
        case HASHTAG:

            break;

        case USUARIOS:

            break;

        case SAIR:
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}