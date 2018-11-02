//
// Created by marcelo on 02/11/18.
//

#include "AbstractInterface.hpp"

AbstractInterface::AbstractInterface(const std::string &titulo) : titulo(titulo) {
    system("clear");
    std::cout << "\b" << titulo << std::endl;
}

const std::string &AbstractInterface::getTitulo() const {
    return titulo;
}
