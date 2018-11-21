//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_COMMENTS_HPP
#define INC_2018_2_GRUPO19_COMMENTS_HPP

#include <iostream>
#include <vector>
#include "AbstractConnection.hpp"
#include "Users.hpp"

class Comments : public AbstractConnection {
 private:
	int id;
	std::string description;
	int tweets_id;
	Users *user;

 public:
	int getId() const;

	void setId(int id);

	const std::string &getDescription() const;

	void setDescription(const std::string &description);

	void inserirComentario(std::string comentario, int idUsuario, int idTweet);

	int getTweets_id() const;

	void setTweets_id(int tweets_id);

	Users *getUser() const;

	void setUser(Users *user);

	vector<Comments> carregarComments(int tweet_id);
};

#endif //INC_2018_2_GRUPO19_COMMENTS_HPP
