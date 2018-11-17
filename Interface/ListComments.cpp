//
// Created by pedro on 11/11/18.
//
#include <iostream>
#include "ListComments.hpp"
#include "Feed.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"

ListComments::ListComments(Tweet *tweet) : AbstractInterface("Comentarios") {
    this->tweet = tweet;
}

void ListComments::exibir() {

    int opcao;
    do {
        exibirComentarios();
        std::cout << "Escolha a opção" << std::endl << "1 - Comentar" << std::endl << "0 - Sair" << std::endl;
//        cin.ignore();
//        cin.get();
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
    } while (opcao != 0);
}

void ListComments::processarEntrada(int opcao) {
    switch (opcao) {
        case 1:
            comentar();
            break;
        case 0:
            return;
        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void ListComments::comentar() {
    std::string texto;

    Comments *comments = new Comments();
    cout << "Digite o comentário:" << endl;
    cin.ignore();
    getline(cin, texto);

    comments->inserirComentario(texto, Session::getUsuarioLogado()->getId(), this->tweet->getId());
    delete (comments);
}

void ListComments::exibirComentarios() {

    Comments *comments = new Comments();

    vector<Comments> listComments = comments->carregarComments(this->tweet->getId());

    for (int i = 0; i < listComments.size(); i++) {
        std::cout << listComments.at(i).getUser()->getProfile() + ": " +
                     listComments.at(i).getDescription() << std::endl;
    }

    delete (comments);
}
