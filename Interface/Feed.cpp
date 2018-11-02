//
// Created by marcelo on 02/11/18.
//

#include "Feed.hpp"

Feed::Feed() : AbstractInterface("Feed") {}

void Feed::exibir() {
    int opcao;
    do {
        std::cout << "Escolha a opção" << std::endl << "1 - Login" << std::endl << "2 - Criar conta" << std::endl
                  << "0 - Sair" << std::endl;
        std::cin >> opcao;
        system("clear");
    } while (opcao != 0);
}

void Feed::processarEntrada(int opcao) {

}
