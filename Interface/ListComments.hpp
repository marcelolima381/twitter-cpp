//
// Created by pedro on 11/11/18.
//
#ifndef INC_2018_2_GRUPO19_LISTCOMMENTS_HPP
#define INC_2018_2_GRUPO19_LISTCOMMENTS_HPP
#include "AbstractInterface.hpp"
#include "../TAD/Tweet.hpp"
#include "../TAD/Comments.hpp"
class ListComments : public AbstractInterface {
public:
    ListComments(Tweet *tweet);
    void exibir() override;
private:
    Tweet *tweet;
    void processarEntrada(int opcao) override;
    void exibirComentarios();
};
#endif //INC_2018_2_GRUPO19_COMMENTS_HPP
