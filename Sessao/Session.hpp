//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_SESSION_HPP
#define INC_2018_2_GRUPO19_SESSION_HPP

#include "../TAD/Users.hpp"

class Session {

 private:
	static Users *usuario;

 public:
	static Users *getUsuarioLogado();

	static void setUsuarioLogado(Users *users);

};

#endif //INC_2018_2_GRUPO19_SESSION_HPP
