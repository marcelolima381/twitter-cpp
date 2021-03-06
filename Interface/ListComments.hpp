//
// Created by pedro on 11/11/18.
//
#ifndef INC_2018_2_GRUPO19_LISTCOMMENTS_HPP
#define INC_2018_2_GRUPO19_LISTCOMMENTS_HPP

#include "AbstractInterface.hpp"
#include "../TAD/Tweet.hpp"
#include "../TAD/Comments.hpp"

namespace Interface {

class ListComments : public Interface::AbstractInterface {
 public:
	explicit ListComments(TAD::Tweet *tweet);

	void exibir() override;

 private:
	TAD::Tweet *tweet;

	void processarEntrada(int opcao) override;

	void exibirComentarios();

	void comentar();
};

}

#endif //INC_2018_2_GRUPO19_COMMENTS_HPP
