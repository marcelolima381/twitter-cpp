//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_FEED_HPP
#define INC_2018_2_GRUPO19_FEED_HPP

#include "AbstractInterface.hpp"
#include "../TAD/Tweet.hpp"

class Feed : public AbstractInterface {
public:
    Feed();

    void exibir() override;

 private:
  	std::vector<Tweet> tweets;
	unsigned long index;

	void processarEntrada(int opcao) override;
	void exibirTweet(Tweet tweet);
};


#endif //INC_2018_2_GRUPO19_FEED_HPP
