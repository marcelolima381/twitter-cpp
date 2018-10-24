//
// Created by Mihawk on 09/10/2018.
//

#include "Feed.h"


Feed::Feed(const std::string &idUsuario) : idUsuario(idUsuario) {}

const std::string &Feed::getIdUsuario() const {
    return idUsuario;
}

void Feed::setIdUsuario(const std::string &idUsuario) {
    Feed::idUsuario = idUsuario;
}
