//
// Created by marcelo on 17/11/18.
//

#ifndef INC_2018_2_GRUPO19_PERFIL_HPP
#define INC_2018_2_GRUPO19_PERFIL_HPP


#include "AbstractInterface.hpp"
#include "../TAD/Tweet.hpp"

class Perfil : public AbstractInterface {

public:
    Perfil();

    void exibir() override;
    void processarEntrada(int opcao) override;

private:
    unsigned long index;
    vector<Tweet> tweets;
};


#endif //INC_2018_2_GRUPO19_PERFIL_HPP