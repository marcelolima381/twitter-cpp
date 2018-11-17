//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Tweet.hpp"

int Tweet::getId() {
    return id;
}

void Tweet::setId(int id) {
    Tweet::id = id;
}

std::string Tweet::getDescription() {
    return description;
}

void Tweet::setDescription(std::string description) {
    Tweet::description = description;
}

Users * Tweet::getUser() {
	return user;
}

void Tweet::setUser(Users *user) {
	Tweet::user = user;
}

vector<Comments> Tweet::getComments() {
	return comments;
}

void Tweet::setComments(vector<Comments> comments) {
	Tweet::comments = comments;
}

vector<Tweet> Tweet::pesquisarPorHashtag(string hashtag) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery("select t.id tweetID, t.description, u.id as idUsuario, u.profile, (select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from   tweets t inner join users u on u.id = t.users_id where t.description like '%" + hashtag +  " %' order by t.id desc");
		std::vector<Tweet> tweets;
		while (res->next()) {
			Tweet *tweet = new Tweet();
			Users *user = new Users();
			Comments *comment = new Comments();
			tweet->setId(res->getInt("tweetID"));
			tweet->setDescription(res->getString("description"));
			user->setProfile(res->getString("profile"));
			user->setId(res->getInt("idUsuario"));
			tweet->setUser(user);
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

vector<Tweet> Tweet::carregarTweetsUsuariosSeguidos(int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery("select t.id tweetID, t.description, u.id as idUsuario, u.profile,(select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from followee f inner join tweets t on t.users_id = f.following inner join users u on u.id = t.users_id where f.follower = " + std::to_string(user_id) +  " order by t.id desc");
		std::vector<Tweet> tweets;
		while (res->next()) {
			Tweet *tweet = new Tweet();
			Users *user = new Users();
			Comments *comment = new Comments();
			tweet->setId(res->getInt("tweetID"));
			tweet->setDescription(res->getString("description"));
			user->setProfile(res->getString("profile"));
			user->setId(res->getInt("idUsuario"));
			tweet->setUser(user);
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

vector<Tweet> Tweet::carregarTweetsUsuarioLogado(int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery("select t.id tweetID, t.description, u.id as idUsuario, u.profile, (select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from   tweets t inner join users u on u.id = t.users_id where u.id = " + std::to_string(user_id) +  " order by t.id desc;");
		std::vector<Tweet> tweets;
		while (res->next()) {
			Tweet *tweet = new Tweet();
			Users *user = new Users();
			Comments *comment = new Comments();
			tweet->setId(res->getInt("tweetID"));
			tweet->setDescription(res->getString("description"));
			user->setProfile(res->getString("profile"));
			user->setId(res->getInt("idUsuario"));
			tweet->setUser(user);
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

void Tweet::avancarTweet(unsigned long index) {

}

void Tweet::retrocederTweet(unsigned long index) {

}

void Tweet::criarTweet(string texto_tweet, int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		stmt->execute("insert into tweets (users_id, description, data) values ('" + std::to_string(user_id) + "','" + texto_tweet + "',now())");
		fecharConexao();

	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		//cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		fecharConexao();
	} catch (std::exception e) {
		cout << "# ERR: " << e.what();
		fecharConexao();
	}
}



