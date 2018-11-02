//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Tweet.hpp"

int Tweet::getId() const {
    return id;
}

void Tweet::setId(int id) {
    Tweet::id = id;
}

const std::string &Tweet::getDetails() const {
    return details;
}

void Tweet::setDetails(const std::string &details) {
    Tweet::details = details;
}

const std::string &Tweet::getDescription() const {
    return description;
}

void Tweet::setDescription(const std::string &description) {
    Tweet::description = description;
}

int Tweet::getUser_id() const {
    return user_id;
}

void Tweet::setUser_id(int user_id) {
    Tweet::user_id = user_id;
}