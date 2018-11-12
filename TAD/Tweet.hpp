//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_TWEET_HPP
#define INC_2018_2_GRUPO19_TWEET_HPP

#include <iostream>
#include <vector>
#include "AbstractConnection.hpp"
#include "Users.hpp"
#include "Comments.hpp"

class Tweet : public AbstractConnection {
private:
    int id;
    std::vector<Comments> comments;
    std::string details;
    std::string description;
    Users *user;

public:
    int getId() const;

    void setId(int id);

    const std::string &getDetails() const;

    void setDetails(const std::string &details);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

	Users * getUser() const;

	void setUser(Users *user);

	const vector<Comments> &getComments() const;

	void setComments(const vector<Comments> &comments);

	std::vector<Tweet> carregarTweetsUsuariosSeguidos(int user_id);

    void avancarTweet(int index);

    void retrocederTweet(int index);
};


#endif //INC_2018_2_GRUPO19_TWEET_HPP
