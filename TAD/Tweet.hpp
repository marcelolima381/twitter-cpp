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
namespace TAD {

class Tweet : public TAD::AbstractConnection {
 private:
	int id;
	std::vector<Comments> comments;
	std::string description;
	Users *user;

 public:
	int getId();

	void setId(int id);

	std::string getDescription();

	void setDescription(std::string description);

	Users *getUser();

	void setUser(Users *user);

	std::vector<Comments> getComments();

	void setComments(std::vector<Comments> comments);

	std::vector<Tweet> carregarTweetsUsuariosSeguidos(int user_id);

	std::vector<Tweet> carregarTweetsUsuarioLogado(int user_id);

	std::vector<Tweet> pesquisarPorHashtag(std::string hashtag);

	void criarTweet(std::string texto_tweet, int user_id);

	void curtirTweet(int tweet_id, int user_id);

	std::vector<Users> verCurtidas(int tweet_id);
};

}
#endif //INC_2018_2_GRUPO19_TWEET_HPP
