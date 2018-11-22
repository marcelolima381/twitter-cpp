//
// Created by marcelo on 17/11/18.
//

#ifndef INC_2018_2_GRUPO19_PERFIL_HPP
#define INC_2018_2_GRUPO19_PERFIL_HPP

#include "AbstractInterface.hpp"
#include "../TAD/Tweet.hpp"
#include <string>

class Perfil : public AbstractInterface {

 public:
	Perfil();

	void exibir() override;

	bool exibir() override;

	void processarEntrada(int &opcao) override;

 private:
	unsigned long index;
	std::vector<TAD::Tweet> tweets;

	TAD::Tweet *ObterTweetPeloIndice();

	void entrarComentarios();

	void exibirTweet(TAD::Tweet tweet);

	void avancarTweet();

	void retrocederTweet();

	bool editarPerfil();
};

#endif //INC_2018_2_GRUPO19_PERFIL_HPP
