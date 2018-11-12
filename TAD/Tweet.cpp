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

Users * Tweet::getUser() const {
	return user;
}

void Tweet::setUser(Users *user) {
	Tweet::user = user;
}

const vector<Comments> &Tweet::getComments() const {
	return comments;
}

void Tweet::setComments(const vector<Comments> &comments) {
	Tweet::comments = comments;
}

vector<Tweet> Tweet::carregarTweetsUsuariosSeguidos(int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery("select t.id tweetID, t.details, t.description, u.id as idUsuario, u.profile,(select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from followee f inner join tweets t on t.users_id = f.following inner join users u on u.id = t.users_id where f.follower = " + std::to_string(user_id) +  " order by t.id desc");
		std::vector<Tweet> tweets;
		while (res->next()) {
			Tweet *tweet = new Tweet();
			Users *user = new Users();
			Comments *comment = new Comments();
			tweet->setId(res->getInt("tweetID"));
			tweet->setDetails(res->getString("details"));
			tweet->setDescription(res->getString("description"));
			user->setProfile(res->getString("profile"));
			user->setId(res->getInt("idUsuario"));
			tweet->setUser(user);
			tweet->setComments(comment->carregarComments(tweet->getId()));
			tweets.push_back(*tweet);
		}
		fecharConexao();
		return tweets;
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

void Tweet::avancarTweet(int index) {

}

void Tweet::retrocederTweet(int index) {

}



