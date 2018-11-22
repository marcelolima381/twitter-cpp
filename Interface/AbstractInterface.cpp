#include "AbstractInterface.hpp"
namespace Interface {

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

}