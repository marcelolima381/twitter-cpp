//
// Created by Fabio Cesar Marra Filho on 29/10/18.
//

#include "Tweet.hpp"
#include <utility>
namespace TAD {

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
	Tweet::description = std::move(description);
}

Users *Tweet::getUser() {
	return user;
}

void Tweet::setUser(Users *user) {
	Tweet::user = user;
}

std::vector<Comments> Tweet::getComments() {
	return comments;
}

void Tweet::setComments(std::vector<Comments> comments) {
	Tweet::comments = std::move(comments);
}
/**
 * @brief Pesquisa no banco de dados tweets que possuam a hashtag do parametro no seu texto, os armazena em um vetor em
 *        ordem decrescente de  acordo seus id's e retorna esse vetor.
 * @param hashtag
 * @return vector<Tweet>
 */
std::vector<Tweet> Tweet::pesquisarPorHashtag(std::string hashtag) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery(
			"select t.id tweetID, t.description, u.id as idUsuario, u.profile, (select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from   tweets t inner join users u on u.id = t.users_id where t.description like '%"
				+
					hashtag + " %' order by t.id desc");
		std::vector<Tweet> tweets;
		while (res->next()) {
			auto *tweet = new Tweet();
			auto *user = new Users();
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
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		fecharConexao();
	} catch (std::exception &e) {
		std::cout << "# ERR: " << e.what();
		fecharConexao();
	}
}
/**
 * @brief Busca no banco de dados os tweets de todos os usuarios seguidos pelo usuário que possui a id passada como
 *        parâmetro, os armazena em um vetor em ordem decrescente de  acordo seus id's e retorna esse vetor.
 * @param user_id
 * @return vector<Tweet>
 */
std::vector<Tweet> Tweet::carregarTweetsUsuariosSeguidos(int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery(
			"select t.id tweetID, t.description, u.id as idUsuario, u.profile,(select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from followee f inner join tweets t on t.users_id = f.following inner join users u on u.id = t.users_id where f.follower = "
				+
					std::to_string(user_id) + " order by t.id desc");
		std::vector<Tweet> tweets;
		while (res->next()) {
			auto *tweet = new Tweet();
			auto *user = new Users();
//			auto *comment = new Comments();
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
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		fecharConexao();
	} catch (std::exception &e) {
		std::cout << "# ERR: " << e.what();
		fecharConexao();
	}
}
/**
 * @brief Busca no banco de dados todos os tweets que sejam do usuário que possua o id passado como parâmetro,
 *        os armazena em um vetor em ordem decrescente de  acordo seus id's e retorna esse vetor.
 * @param user_id
 * @return vector<Tweet>
 */
std::vector<Tweet> Tweet::carregarTweetsUsuarioLogado(int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery(
			"select t.id tweetID, t.description, u.id as idUsuario, u.profile, (select count(1) from comments c1 where c1.tweets_id = t.id) NumeroComentarios from   tweets t inner join users u on u.id = t.users_id where u.id = "
				+
					std::to_string(user_id) + " order by t.id desc;");
		std::vector<Tweet> tweets;
		while (res->next()) {
			auto *tweet = new Tweet();
			auto *user = new Users();
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
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		fecharConexao();
	} catch (std::exception &e) {
		std::cout << "# ERR: " << e.what();
		fecharConexao();
	}
}

/**
 * @brief Adiciona ao banco de dados um tweet, armazenando seu texto passado e usuário que tweetou, que são
 *        passados como parâmetro
 * @param texto_tweet
 * @param user_id
 */
void Tweet::criarTweet(std::string texto_tweet, int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		stmt->execute("insert into tweets (users_id, description, data) values ('" + std::to_string(user_id) + "','" +
			texto_tweet + "',now())");
		fecharConexao();

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		//cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		fecharConexao();
	} catch (std::exception &e) {
		std::cout << "# ERR: " << e.what();
		fecharConexao();
	}
}
/**
 * @brief Adiciona ao banco de dados um "like", com o id do tweet curtido e o id do usuário que curtiu
 * @param tweet_id
 * @param user_id
 */
void Tweet::curtirTweet(int tweet_id, int user_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		stmt->execute("INSERT INTO tweets_likes (tweets_id, users_id) VALUES (" + std::to_string(tweet_id) + ", " +
			std::to_string(user_id) + ")");
		fecharConexao();

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		//cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		fecharConexao();
	} catch (std::exception &e) {
		std::cout << "# ERR: " << e.what();
		fecharConexao();
	}
}
/**
 * @brief Busca no banco de dados todos os "likes" que possuam o id do tweet passado como parâmetro, pega o id do
 *        usuário de cada "like", resgata os dados de cada usuário, os armazena em um vector e o retorna
 * @param tweet_id
 * @return vector<Users>
 */
std::vector<Users> Tweet::verCurtidas(int tweet_id) {
	try {
		abrirConexao();
		stmt = con->createStatement();
//        Query SQL
		res = stmt->executeQuery(
			"select u.id, u.profile, u.name from tweets t join tweets_likes t2 on t.id = t2.tweets_id join users u on t2.users_id = u.id where t.id = "
				+
					std::to_string(tweet_id) + ";");
		std::vector<Users> users;
		while (res->next()) {
			auto *user = new Users();
			user->setId(res->getInt("id"));
			user->setProfile(res->getString("profile"));
			user->setName(res->getString("name"));
			users.push_back(*user);
		}
		fecharConexao();
		return users;
	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		fecharConexao();
	} catch (std::exception &e) {
		std::cout << "# ERR: " << e.what();
		fecharConexao();
	}
}

}