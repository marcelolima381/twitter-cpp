//
// Created by marcelo on 02/11/18.
//

#include "AbstractConnection.hpp"
/**
 * @brief Abre conexão com o banco de dados nas classes que herdam de AbstractConnetcion
 */
void AbstractConnection::abrirConexao() {
//        Criando conexão
	driver = get_driver_instance();
//        Dados do banco MySQL
	con = driver->connect("tcp://91.121.180.213:3305", "myuser", "mypass");
//        Escolhendo o database
	con->setSchema("twittercpp");
}
/**
 * @brief Fecha conexão com o banco de dados nas classes que herdam de AbstractConnetcion
 */
void AbstractConnection::fecharConexao() {
	delete res;
	delete stmt;
	delete con;
}
