//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Tweets_likes.hpp"

int Tweets_likes::getId() const {
    return id;
}

void Tweets_likes::setId(int id) {
    Tweets_likes::id = id;
}

int Tweets_likes::getTweets_id() const {
    return tweets_id;
}

void Tweets_likes::setTweets_id(int tweets_id) {
    Tweets_likes::tweets_id = tweets_id;
}

int Tweets_likes::getUsers_id() const {
    return users_id;
}

void Tweets_likes::setUsers_id(int users_id) {
    Tweets_likes::users_id = users_id;
}