//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Followee.hpp"

int Followee::getId() const {
	return id;
}

void Followee::setId(int id) {
	Followee::id = id;
}

int Followee::getFollower() const {
	return follower;
}

void Followee::setFollower(int follower) {
	Followee::follower = follower;
}

int Followee::getFollowing() const {
	return following;
}

void Followee::setFollowing(int following) {
	Followee::following = following;
}