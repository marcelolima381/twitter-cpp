//
// Created by marcelo on 02/11/18.
//

#include "AbstractConnection.hpp"
namespace TAD {

/**
* @brief Abre conexão com o banco de dados nas classes que herdam de AbstractConnetcion
*/
void AbstractConnection::abrirConexao() {
//        Criando conexão
	driver = get_driver_instance();
//        Dados do banco MySQL
	con = driver->connect("tcp://127.0.0.1:3306", "marcelo", "fsohexbpf123");
//        Escolhendo o database
	con->setSchema("twittercpp");
}
/**
 * @brief Fecha conexão com o banco de dados nas classes que herdam de AbstractConnetcion
 */
void AbstractConnection::fecharConexao() {
	if (res != NULL)
		delete res;

	delete stmt;
	delete con;
}

}

