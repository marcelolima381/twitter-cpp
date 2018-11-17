//
// Created by pedro on 17/11/18.
//

#include "Pesquisa.hpp"
#include "../TAD/Tweet.hpp"
#include "../Sessao/Session.hpp"
#include "ListComments.hpp"
#include <iomanip>

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
            pesquisarHashTag();
            break;

        case USUARIOS:
            pesquisarUsuario();
            break;

        case SAIR:
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Pesquisa::pesquisarUsuario() {
    std::string pesquisa;

    cout<<"Digite o que pesquisa:"<<std::endl;
    cin.ignore();
    getline(cin, pesquisa);

    Users *user = new Users();

    usuariosPesquisados = user->pesquisarUsuarios(pesquisa);
    exibirUsuariosPesquisados();
}

void Pesquisa::pesquisarHashTag() {
    std::string pesquisa;

    cout<<"Digite o que pesquisa:"<<std::endl;
    cin.ignore();
    getline(cin, pesquisa);
}

void Pesquisa::exibirUsuariosPesquisados() {
    if(usuariosPesquisados.size()>0) {
        for (unsigned long i = 0; i < usuariosPesquisados.size(); ++i) {
            cout << "ID: " << setw(3) << left << std::to_string(usuariosPesquisados.at(i).getId()) <<
                 "Profile: " << setw(20) << left << usuariosPesquisados.at(i).getProfile() <<
                 " Nome: " << setw(30) << left << usuariosPesquisados.at(i).getName() << std::endl;
        }
        associarUsuario();
    }
    else{
        cout<< "Não foram encontrados usuários." <<std::endl;
    }

}

void Pesquisa::associarUsuario()
{
    int id;

    do
    {
        cout<<std::endl<<"Digite o ID do usuário para segui-lo, ou digite 0 para voltar."<<std::endl;
        cin>>id;

        if(id!=0)
        {
            for (unsigned long i = 0; i < usuariosPesquisados.size(); ++i) {
                if(usuariosPesquisados.at(i).getId()==id) {
                    Users *user = new Users();

                    user->seguirUsuario(Session::getUsuarioLogado()->getId(), id);

                    cout << "Você agora segue o usuário: " << usuariosPesquisados.at(i).getProfile();
                    return;
                }
            }
            cout << "ID não encontrado."<<std::endl;
        }

    }while(id!=0);
}
