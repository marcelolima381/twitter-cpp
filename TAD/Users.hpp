//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_USERS_HPP
#define INC_2018_2_GRUPO19_USERS_HPP

#include <iostream>

class Users {
private:
    int id;
    std::string acount;
    std::string password;
    std::string profile;
    std::string name;
    int age;
    std::string city;

public:
    int getId() const;

    void setId(int id);

    const std::string &getAcount() const;

    void setAcount(const std::string &acount);

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
};

#endif //INC_2018_2_GRUPO19_USERS_HPP
