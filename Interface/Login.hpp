//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_LOGIN_HPP
#define INC_2018_2_GRUPO19_LOGIN_HPP

#include "AbstractInterface.hpp"

namespace Interface {

class Login : public Interface::AbstractInterface {
 public:
	Login();

	void exibir() override;

 private:

	void processarEntrada(int opcao) override;

	void logar();

	void criarConta();
};

}
#endif //INC_2018_2_GRUPO19_LOGIN_HPP
