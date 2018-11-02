//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_FEED_HPP
#define INC_2018_2_GRUPO19_FEED_HPP

#include "AbstractInterface.hpp"

class Feed : public AbstractInterface {
public:
    Feed();

    void exibir() override;
private:

    void processarEntrada(int opcao) override;
};


#endif //INC_2018_2_GRUPO19_FEED_HPP
