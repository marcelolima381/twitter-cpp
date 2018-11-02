//
// Created by Mihawk on 09/10/2018.
//

#ifndef CLASSESTWITTER_USUARIO_H
#define CLASSESTWITTER_USUARIO_H
#include <iostream>
#include <vector>
#include "Tweet.h"

class Usuario {
private:
    std::string login, senha, perfil, nome, cidade;

    int id, idade;

public:

    Usuario(const std::string &login, const std::string &senha, const std::string &perfil, const std::string &nome,
            const std::string &cidade, int id, int idade);

    const std::string &getLogin() const;

    void setLogin(const std::string &login);

    const std::string &getSenha() const;

    void setSenha(const std::string &senha);

    const std::string &getPerfil() const;

    void setPerfil(const std::string &perfil);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    const std::string &getCidade() const;

    void setCidade(const std::string &cidade);

    int getId() const;

    void setId(int id);

    int getIdade() const;

    void setIdade(int idade);

    std::vector<Tweet> MeusTweets();
};


#endif //CLASSESTWITTER_USUARIO_H
