//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Users.hpp"
#include "../Sessao/Session.hpp"

int Users::getId() const {
    return id;
}

void Users::setId(int id) {
    Users::id = id;
}

const std::string &Users::getAccount() const {
    return account;
}

void Users::setAccount(const std::string &account) {
    Users::account = account;
}

const std::string &Users::getPassword() const {
    return password;
}

void Users::setPassword(const std::string &password) {
    Users::password = password;
}

const std::string &Users::getProfile() const {
    return profile;
}

void Users::setProfile(const std::string &profile) {
    Users::profile = profile;
}

const std::string &Users::getName() const {
    return name;
}

void Users::setName(const std::string &name) {
    Users::name = name;
}

int Users::getAge() const {
    return age;
}

void Users::setAge(int age) {
    Users::age = age;
}

const std::string &Users::getCity() const {
    return city;
}

void Users::setCity(const std::string &city) {
    Users::city = city;
}
/**
 * @brief Busca no banco de dados o usuário com o id passado como parâmetro e armazena seus dados em um objeto users
 * @param user_id
 * @return *Users
 */
Users *Users::buscarUsuario(int user_id) {
    try {
        abrirConexao();
        stmt = con->createStatement();
//        Query SQL
        res = stmt->executeQuery("SELECT * FROM users WHERE id='" + std::to_string(user_id) + "'");
        res->next();
        Users *user = new Users();
        if (res->rowsCount()) {
            user->setId(res->getInt("id"));
            user->setAccount(res->getString("account"));
            user->setPassword(res->getString("password"));
            user->setProfile(res->getString("profile"));
            user->setName(res->getString("name"));
            user->setAge(res->getInt("age"));
            user->setCity(res->getString("city"));
            fecharConexao();
            return user;
        } else {
            fecharConexao();
            cout << "Usuário não encontrado" << std::endl;
            throw std::exception();
        }
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        fecharConexao();
    } catch (std::exception e) {
        cout << "# ERR: " << e.what();
        fecharConexao();
    }
}
/**
 * @brief Busca no banco de dados se há algum usuário que possui a conta e a senha passada como parâmetro
 * @param conta
 * @param senha
 * @return Bool
 */
bool Users::validarLogin(std::string conta, std::string senha) {
    try {
        abrirConexao();
        stmt = con->createStatement();
//        Query SQL
        res = stmt->executeQuery("SELECT * FROM users WHERE account='" + conta + "' AND password='" + senha + "'");
        res->next();
        if (res->rowsCount()) {
            this->setId(res->getInt("id"));
            this->setAccount(res->getString("account"));
            this->setPassword(res->getString("password"));
            this->setProfile(res->getString("profile"));
            this->setName(res->getString("name"));
            this->setAge(res->getInt("age"));
            this->setCity(res->getString("city"));
            fecharConexao();
            return true;
        } else {
            fecharConexao();
            return false;
        }
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        fecharConexao();
    } catch (std::exception e) {
        cout << "# ERR: " << e.what();
        fecharConexao();
    }
}
/**
 * @brief Adiciona no banco de dados um novo usuário com os dados passados como parâmetro
 * @param account
 * @param password
 * @param profile
 * @param name
 * @param city
 * @param age
 * @return string
 */
string Users::criarConta(string account, string password, string profile, string name, string city, int age) {
    try {
        abrirConexao();
        stmt = con->createStatement();
//        Query SQL
        stmt->execute("INSERT INTO users (account, password, profile, name, age, city) VALUES "
                      "('" + account + "','" + password + "', '" + profile + "', '" + name + "', " +
                      std::to_string(age) +
                      ", '" + city + "')");
        fecharConexao();
        this->setAccount(account);
        this->setPassword(password);
        this->setProfile(profile);
        this->setName(name);
        this->setCity(city);
        this->setAge(age);
        return "";

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        //cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        fecharConexao();
        return "Ocorreu um erro ao criar o usuario";
    } catch (std::exception e) {
        cout << "# ERR: " << e.what();
        fecharConexao();
        return "Ocorreu um erro ao criar o usuario";
    }
}

/**
 * @brief Adiciona no banco de dados o id da dupla: seguidor e quem ele deseja seguir, paddados por paraâmetro
 * @param id1
 * @param id2
 */
void Users::seguirUsuario(int id1, int id2) {
    try {
        abrirConexao();
        stmt = con->createStatement();
        stmt->execute(
                "insert into followee(follower,following) values (" + std::to_string(id1) + "," + std::to_string(id2) +
                ")");
        fecharConexao();
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        //cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        fecharConexao();
    } catch (std::exception e) {
        cout << "# ERR: " << e.what();
        fecharConexao();
    }
}
/**
 * @brief Pesquisa no banco de dados usuários que possuam uma conta, ou nome, ou profile de acordo com o que foi
 *        pesquisado, que é passado como parâmetro
 * @param pesquisa
 * @return vector<Users>
 */
std::vector<Users> Users::pesquisarUsuarios(string pesquisa) {

    try {
        abrirConexao();
        stmt = con->createStatement();
//        Query SQL
        res = stmt->executeQuery(
                "select  id, profile, name from users where profile like '%" + pesquisa + "%' or account like '%" +
                pesquisa + "%' or name like '%" + pesquisa + "%'");
        std::vector<Users> usuarios;
        while (res->next()) {
            Users *user = new Users();
            user->setId(res->getInt("id"));
            user->setProfile(res->getString("profile"));
            user->setName(res->getString("name"));

            usuarios.push_back(*user);
        }
        fecharConexao();
        return usuarios;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        fecharConexao();
    } catch (std::exception e) {
        cout << "# ERR: " << e.what();
        fecharConexao();
    }

    return vector<Users>();
}
/**
 * @brief Receb como parâmetro o campo que se deseja editar e a nova informação que se deseja inserir e atualiza o
 *        banco de dados
 * @param coluna
 * @param valor
 */
void Users::editarCampo(string coluna, string valor) {
    try {
        abrirConexao();
        stmt = con->createStatement();
//        Query SQL
        stmt->execute("UPDATE users t SET t." + coluna + " = '" + valor + "' WHERE t.id = " +
                      std::to_string(Session::getUsuarioLogado()->getId()));
        fecharConexao();
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        //cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        fecharConexao();
    } catch (std::exception e) {
        cout << "# ERR: " << e.what();
        fecharConexao();
    }
}
