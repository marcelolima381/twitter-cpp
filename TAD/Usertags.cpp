//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Usertags.hpp"

int Usertags::getId() const {
    return id;
}

void Usertags::setId(int id) {
    Usertags::id = id;
}

const std::string &Usertags::getName() const {
    return name;
}

void Usertags::setName(const std::string &name) {
    Usertags::name = name;
}

int Usertags::getTweets_id() const {
    return tweets_id;
}

void Usertags::setTweets_id(int tweets_id) {
    Usertags::tweets_id = tweets_id;
}