#include <utility>

//
// Created by marcelo on 02/11/18.
//

#include "Session.hpp"
namespace Sessao {
TAD::Users *Session::getUsuarioLogado() {
	return Session::usuario;
}
/**
 * @brief Abre a sessão de um usuário, sendo a referência de qual conta está logada
 * @param users
 */
void Session::setUsuarioLogado(TAD::Users *users) {
	Session::usuario = users;
}

TAD::Users *Session::usuario = nullptr;

}