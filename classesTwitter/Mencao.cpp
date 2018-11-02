//
// Created by Mihawk on 09/10/2018.
//

#include "Mencao.h"

Mencao::Mencao(const std::string &idTweet) : idTweet(idTweet) {}

const std::string &Mencao::getIdTweet() const {
    return idTweet;
}

void Mencao::setIdTweet(const std::string &idTweet) {
    Mencao::idTweet = idTweet;
}
