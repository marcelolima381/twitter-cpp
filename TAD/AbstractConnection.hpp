//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_ABSTRACTCONNECTION_HPP
#define INC_2018_2_GRUPO19_ABSTRACTCONNECTION_HPP

/* Standard C++ includes */
#include <cstdlib>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

namespace TAD {

class AbstractConnection {
 protected:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;

	void abrirConexao();

	void fecharConexao();
};

}


#endif //INC_2018_2_GRUPO19_ABSTRACTCONNECTION_HPP
