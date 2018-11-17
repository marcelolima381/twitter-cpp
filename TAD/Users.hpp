//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_USERS_HPP
#define INC_2018_2_GRUPO19_USERS_HPP

#include <iostream>
#include "AbstractConnection.hpp"

class Users : public AbstractConnection {
private:
    int id;
    std::string account;
    std::string password;
    std::string profile;
    std::string name;
    int age;
    std::string city;

public:
    int getId() const;

    void setId(int id);

    const std::string &getAccount() const;

    void setAccount(const std::string &account);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    const std::string &getProfile() const;

    void setProfile(const std::string &profile);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getAge() const;

    void setAge(int age);

    const std::string &getCity() const;

    void setCity(const std::string &city);

    Users * buscarUsuario(int user_id);

    bool validarLogin(std::string conta, std::string senha);

    string criarConta(string basicString, string string1, string string2, string string3, string string4, int i);

    void editarCampo(string coluna, string valor);
};

#endif //INC_2018_2_GRUPO19_USERS_HPP
