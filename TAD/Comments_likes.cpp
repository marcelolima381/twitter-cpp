//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Comments_likes.hpp"

int Comments_likes::getId() const {
    return id;
}

void Comments_likes::setId(int id) {
    Comments_likes::id = id;
}

int Comments_likes::getUsers_id() const {
    return users_id;
}

void Comments_likes::setUsers_id(int users_id) {
    Comments_likes::users_id = users_id;
}

int Comments_likes::getComments_id() const {
    return comments_id;
}

void Comments_likes::setComments_id(int comments_id) {
    Comments_likes::comments_id = comments_id;
}