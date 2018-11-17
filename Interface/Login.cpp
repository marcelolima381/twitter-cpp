//
// Created by marcelo on 02/11/18.
//

#include <iostream>
#include "Login.hpp"
#include "../TAD/Users.hpp"
#include "../Sessao/Session.hpp"
#include "Feed.hpp"


Login::Login() : AbstractInterface("Twitter") {}

void Login::exibir() {
    int opcao;
    do {
        std::cout << "Escolha a opção" << std::endl << "1 - Login" << std::endl << "2 - Criar conta" << std::endl
                  << "0 - Sair" << std::endl;
        std::cin >> opcao;
        this->processarEntrada(opcao);
        std::cout << "Coe" << std::endl;
        system("clear");
    } while (opcao != 0);
}

void Login::processarEntrada(int opcao) {
    switch (opcao) {
        case 1:
            logar();
            break;

        case 2:
            criarConta();
            break;

        case 0:
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Login::logar() {
    std::string conta, senha;
    std::cout << "Login: ";
    std::cin >> conta;
    std::cout << "Senha: ";
    std::cin >> senha;
    Users *user = new Users();

    cout<<"Validando login..."<<std::endl;
    bool flag = user->validarLogin(conta, senha);
    if (flag) {
        Session::setUsuarioLogado(user);
        Feed *feed = new Feed();
        feed->exibir();
    } else {
        std::cout << "Login ou senha inválido." << endl;
    }


}

void Login::criarConta() {
    std::string account, password, profile, name, city, retornoCriacao;
    int age;

    std::cout << "Insira os dados da sua nova conta." << std::endl;
    std::cout << "Apelido: ";
    cin.ignore();
    getline(cin, profile);
    std::cout << "Senha: ";
    cin.ignore();
    std::cin >> password;
    std::cout << "Email: ";
    cin.ignore();
    std::cin >> account;
    std::cout << "Nome: ";
    cin.ignore();
    getline(cin, name);
    std::cout << "Idade: ";
    cin.ignore();
    std::cin >> age;
    std::cout << "Cidade: ";
    cin.ignore();
    getline(cin, city);

    Users *user = new Users();

    retornoCriacao = user->criarConta(account, password, profile, name, city, age);

    cout<<"Usuario "+profile+" criado!" << std::endl;
}

void Login::redirecionarParaFeed() {

}
