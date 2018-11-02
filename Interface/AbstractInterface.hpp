//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_ABSTRACTINTERFACE_HPP
#define INC_2018_2_GRUPO19_ABSTRACTINTERFACE_HPP

#include <iostream>

class AbstractInterface {
private:
    std::string titulo;
public:
    AbstractInterface(const std::string &titulo);

    virtual void exibir() = 0;

    virtual void processarEntrada(int opcao) = 0;

    const std::string &getTitulo() const;
};


#endif //INC_2018_2_GRUPO19_ABSTRACTINTERFACE_HPP
