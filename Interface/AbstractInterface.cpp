/**
 * @file AbstractInterface.cpp
 * @author Marcelo
 * @brief Interface Abstrata
 */
#include "AbstractInterface.hpp"
/**
 * Construtor
 * @param titulo
 */
AbstractInterface::AbstractInterface(const std::string &titulo) : titulo(titulo) {
	system("clear");
	std::cout << "\b" << titulo << std::endl;
}

/**
 * GET titulo
 * @return titulo
 */
const std::string &AbstractInterface::getTitulo() const {
	return titulo;
}
