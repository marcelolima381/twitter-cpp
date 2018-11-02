//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Users.hpp"

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

string Users::criarConta(string account, string password, string profile, string name, string city, int age) {
    try {
        abrirConexao();
        stmt = con->createStatement();
//        Query SQL
        stmt->execute("INSERT INTO users (account, password, profile, name, age, city) VALUES "
                                 "('" + account + "','" + password + "', '" + profile + "', '" + name + "', " + std::to_string(age) +
                                 ", '"+ city + "')");
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
