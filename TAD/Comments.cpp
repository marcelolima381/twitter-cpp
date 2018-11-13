//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Comments.hpp"
#include <vector>

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

Users *Comments::getUser() const {
	return user;
}

void Comments::setUser(Users *user) {
	Comments::user = user;
}

std::vector<Comments> Comments::carregarComments(int tweet_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery("select c.id,description,tweets_id,users_id, u.profile from comments c inner join users u on u.id = c.users_id where tweets_id=" + std::to_string(tweet_id)+" order by c.id desc1");
		std::vector<Comments> comments;
		while (res->next()) {
			Comments *comment = new Comments();
			Users *user = new Users();
			comment->setId(res->getInt("id"));
			comment->setDescription(res->getString("description"));
			comment->setTweets_id(res->getInt("tweets_id"));
			user->setId(res->getInt("users_id"));
			user->setProfile(res->getString("profile"));
			comment->setUser(user);
			comments.push_back(*comment);
		}
		fecharConexao();
		return comments;
	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		fecharConexao();
	} catch (std::exception e) {
		cout << "# ERR: " << e.what();
		fecharConexao();
	}
}

