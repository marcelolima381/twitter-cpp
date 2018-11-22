//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_FEED_HPP
#define INC_2018_2_GRUPO19_FEED_HPP

#include "AbstractInterface.hpp"
#include "ListComments.hpp"
#include "../TAD/Tweet.hpp"

class Feed : public AbstractInterface {
 public:
	Feed();

	void exibir() override;

 private:
	std::vector<TAD::Tweet> tweets;
	unsigned long index;

	TAD::Tweet *ObterTweetPeloIndice();

	void processarEntrada(int opcao) override;

	void exibirTweet(TAD::Tweet tweet);

	void entrarComentarios();

	void entrarPerfil();

	void entrarPesquisa();

	void avancarTweet();

	void retrocederTweet();

	void tweetar();
};

#endif //INC_2018_2_GRUPO19_FEED_HPP
