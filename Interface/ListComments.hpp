//
// Created by pedro on 11/11/18.
//
#ifndef INC_2018_2_GRUPO19_LISTCOMMENTS_HPP
#define INC_2018_2_GRUPO19_LISTCOMMENTS_HPP
#include "AbstractInterface.hpp"
class ListComments : public AbstractInterface {
public:
    ListComments(int idTweet);
    void exibir() override;
private:
    int idTweet;
    void processarEntrada(int opcao) override;
};
#endif //INC_2018_2_GRUPO19_COMMENTS_HPP
