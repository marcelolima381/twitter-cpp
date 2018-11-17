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
#define EDITAR_PERFIL 5

Perfil::Perfil() : AbstractInterface("Perfil") {}

void Perfil::exibir() {
    int opcao;
    Users *user = new Users();
    std::cout << "Perfil: " << Session::getUsuarioLogado()->getProfile() << std::endl << "Nome: "
              << Session::getUsuarioLogado()->getName() << std::endl << "Cidade: "
              << Session::getUsuarioLogado()->getCity() << std::endl << "Idade: "
              << Session::getUsuarioLogado()->getAge() << std::endl;
    Tweet *tweet = new Tweet();
    tweets = tweet->carregarTweetsUsuarioLogado(Session::getUsuarioLogado()->getId());
    index = 0;
    do {
        if (tweets.size() == 0) {
            std::cout << "Você não tem tweets para exibir" << std::endl;
            std::cout << "Escolha a opção:" << std::endl << "3 - Feed" << std::endl << " 5 - Editar perfil"
                      << std::endl;
        } else {
            exibirTweet(tweets.at(this->index));
            std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2- Retroceder" << std::endl
                      << "3 - Feed" << std::endl << "4 - Ver Comentários" << std::endl << "5 - Editar perfil"
                      << std::endl;
        }
        std::cin >> opcao;
        this->processarEntrada(opcao);
        system("clear");
        if (opcao == 3) {
            opcao = 0;
        }
    } while (opcao != 0);
}

void Perfil::processarEntrada(int opcao) {
    switch (opcao) {
        case AVANCAR:
            if (tweets.size() == 0) {
                std::cout << "Opção inválida. Você não tem tweets para exibir. Crie um tweet." << std::endl;
            } else {
                avancarTweet();
            }
            break;

        case RETROCEDER:
            if (tweets.size() == 0) {
                std::cout << "Opção inválida. Você não tem tweets para exibir. Crie um tweet." << std::endl;
            } else {
                retrocederTweet();
            }
            break;

        case FEED:
            return;
            break;

        case COMENTARIOS:
            entrarComentarios();
            break;

        case EDITAR_PERFIL:
            editarPerfil();
            break;

        default:
            std::cout << "Opção inválida!. Digite outra opção." << std::endl;
    }
}

void Perfil::entrarComentarios() {
    ListComments *listComments = new ListComments(ObterTweetPeloIndice());
    listComments->exibir();
}

Tweet *Perfil::ObterTweetPeloIndice() {
    return &tweets.at(index);
};

void Perfil::exibirTweet(Tweet tweet) {
    std::cout << "Tweet " + std::to_string((index + 1)) + " de " + std::to_string(tweets.size()) << std::endl;
    std::cout << std::endl << tweet.getUser()->getProfile() << ":" << std::endl;
    std::cout << tweet.getDescription() << std::endl << std::endl;
}

void Perfil::avancarTweet() {

    if (this->index + 1 >= tweets.size()) {
        system("clear");
        std::cout << "Não é possível avançar mais." << std::endl;
    } else
        this->index++;
}

void Perfil::retrocederTweet() {
    if (this->index <= 0) {
        system("clear");
        std::cout << "Não é possível retroceder mais." << std::endl;
    } else
        this->index--;
}

void Perfil::editarPerfil() {
    Users *user = new Users();
    int opcao;
    string nome, cidade, senha;
    int idade;
    std::cout << "Qual dado do perfil você deseja editar?" << std::endl << "1 - Nome" << std::endl << "2 - Cidade"
              << std::endl << "3 - Idade" << std::endl << "4 - Senha" << std::endl;
    std::cin >> opcao;
    switch (opcao) {
        case 1:
            std::cout << "Digite o novo nome" << std::endl;
            std::cin >> nome;
            user->editarCampo("name", nome);
            Session::getUsuarioLogado()->setName(nome);
            break;

        case 2:
            std::cout << "Digite a nova cidade" << std::endl;
            std::cin >> cidade;
            user->editarCampo("city", cidade);
            Session::getUsuarioLogado()->setCity(cidade);
            break;

        case 3:
            std::cout << "Digite a nova idade" << std::endl;
            std::cin >> idade;
            user->editarCampo("age", std::to_string(idade));
            Session::getUsuarioLogado()->setAge(idade);
            break;

        case 4:
            std::cout << "Digite o novo senha" << std::endl;
            std::cin >> senha;
            user->editarCampo("password", senha);
            Session::getUsuarioLogado()->setPassword(senha);
            break;
    }
}
