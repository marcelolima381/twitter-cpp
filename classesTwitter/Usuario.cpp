//
// Created by Mihawk on 09/10/2018.
//

#include "Usuario.h"


Usuario::Usuario(const std::string &login, const std::string &senha, const std::string &perfil, const std::string &nome,
                 const std::string &cidade, int id, int idade) : login(login), senha(senha), perfil(perfil), nome(nome),
                                                                 cidade(cidade), id(id), idade(idade) {}

const std::string &Usuario::getLogin() const {
    return login;
}

void Usuario::setLogin(const std::string &login) {
    Usuario::login = login;
}

const std::string &Usuario::getSenha() const {
    return senha;
}

void Usuario::setSenha(const std::string &senha) {
    Usuario::senha = senha;
}

const std::string &Usuario::getPerfil() const {
    return perfil;
}

void Usuario::setPerfil(const std::string &perfil) {
    Usuario::perfil = perfil;
}

const std::string &Usuario::getNome() const {
    return nome;
}

void Usuario::setNome(const std::string &nome) {
    Usuario::nome = nome;
}

const std::string &Usuario::getCidade() const {
    return cidade;
}

void Usuario::setCidade(const std::string &cidade) {
    Usuario::cidade = cidade;
}

int Usuario::getId() const {
    return id;
}

void Usuario::setId(int id) {
    Usuario::id = id;
}

int Usuario::getIdade() const {
    return idade;
}

void Usuario::setIdade(int idade) {
    Usuario::idade = idade;
}
