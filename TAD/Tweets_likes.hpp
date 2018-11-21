//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_TWEETS_LIKES_HPP
#define INC_2018_2_GRUPO19_TWEETS_LIKES_HPP

#include <iostream>

class Tweets_likes {
 private:
	int id;
	int tweets_id;
	int users_id;

 public:
	int getId() const;

	void setId(int id);

	int getTweets_id() const;

	void setTweets_id(int tweets_id);

	int getUsers_id() const;

	void setUsers_id(int users_id);
};

#endif //INC_2018_2_GRUPO19_TWEETS_LIKES_HPP
