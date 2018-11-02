//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Comments.hpp"

int Comments::getId() const {
    return id;
}

void Comments::setId(int id) {
    Comments::id = id;
}

const std::string &Comments::getDescription() const {
    return description;
}

void Comments::setDescription(const std::string &description) {
    Comments::description = description;
}

int Comments::getTweets_id() const {
    return tweets_id;
}

void Comments::setTweets_id(int tweets_id) {
    Comments::tweets_id = tweets_id;
}