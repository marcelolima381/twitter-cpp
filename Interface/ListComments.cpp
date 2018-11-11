//
// Created by pedro on 11/11/18.
//
#include <iostream>
#include "ListComments.hpp"
#include "Feed.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
ListComments::ListComments(int idTweet) : AbstractInterface("Comentarios") {
    this->idTweet = idTweet;
}
void ListComments::exibir() {
    int opcao;
    do {
        std::cout << "Escolha a opção" << std::endl << "1 - Comentar"  << std::endl << "0 - Sair" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
    } while (opcao != 0);
}
void ListComments::processarEntrada(int opcao) {
    switch (opcao) {
        case 1:
            break;
        case 0:
            return;
        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}
