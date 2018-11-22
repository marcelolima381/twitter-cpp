//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_SESSION_HPP
#define INC_2018_2_GRUPO19_SESSION_HPP

#include "../TAD/Users.hpp"

namespace Sessao {
class Session {

 private:
	static TAD::Users *usuario;

 public:
	static TAD::Users *getUsuarioLogado();

	static void setUsuarioLogado(TAD::Users *users);

};

}

#endif //INC_2018_2_GRUPO19_SESSION_HPP
