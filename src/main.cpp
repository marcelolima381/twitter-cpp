#include <iostream>
#include <string>
#include "Usuario.hpp"
#include "Tweet.hpp"

int main() {
    std::cout << "Execucao teste" << std::endl;

    Usuario* usuario = new Usuario("pedro", "123456", "Ola", "Pedro Henrique", "Belo Horizonte", 1, 28);

    std::vector<Tweet> tweetsUsuario = usuario->MeusTweets();
    for(auto tweet: tweetsUsuario) {
        std::cout << tweet.getTexto() << std::endl;
    }

    return 0;
}