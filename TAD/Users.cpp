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

const std::string &Users::getAcount() const {
    return acount;
}

void Users::setAcount(const std::string &acount) {
    Users::acount = acount;
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