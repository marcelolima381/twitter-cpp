//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_LOGIN_HPP
#define INC_2018_2_GRUPO19_LOGIN_HPP

#include "AbstractInterface.hpp"

class Login : public AbstractInterface {
 public:
	Login();

	void exibir() override;

 private:

	void processarEntrada(int opcao) override;

	void logar();

	void criarConta();

	void redirecionarParaFeed();
};

#endif //INC_2018_2_GRUPO19_LOGIN_HPP
