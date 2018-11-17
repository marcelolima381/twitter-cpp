//
// Created by pedro on 17/11/18.
//

#ifndef INC_2018_2_GRUPO19_PESQUISA_HPP
#define INC_2018_2_GRUPO19_PESQUISA_HPP

#include "AbstractInterface.hpp"
#include "../TAD/Tweet.hpp"
#include "../TAD/Users.hpp"

class Pesquisa : public AbstractInterface {

public:
    Pesquisa();

    void exibir() override;
    void processarEntrada(int opcao) override;

private:

};


#endif //INC_2018_2_GRUPO19_PESQUISA_HPP
