#include <utility>

//
// Created by marcelo on 02/11/18.
//

#include "Session.hpp"

Users* Session::getUsuarioLogado() {
    return Session::usuario;
}

void Session::setUsuarioLogado(Users* users) {
    Session::usuario = users;
}

Users* Session::usuario = nullptr;