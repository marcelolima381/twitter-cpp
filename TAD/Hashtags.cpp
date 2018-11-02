//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Hashtags.hpp"

int Hashstags::getId() const {
    return id;
}

void Hashstags::setId(int id) {
    Hashstags::id = id;
}

const std::string &Hashstags::getName() const {
    return name;
}

void Hashstags::setName(const std::string &name) {
    Hashstags::name = name;
}

int Hashstags::getTweets_id() const {
    return tweets_id;
}

void Hashstags::setTweets_id(int tweets_id) {
    Hashstags::tweets_id = tweets_id;
}