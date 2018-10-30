//
// Created by pedro on 29/10/2018.
//

#ifndef CLASSESTWITTER_TWEET_H
#define CLASSESTWITTER_TWEET_H
#include <iostream>
#include <vector>

class Tweet {
private:
    std::string texto;

    int id, idUsuario, idRetweet, numeroCurtidas, numeroRetweets;
    bool retweeted;

public:

    Tweet(const std::string &texto, int id, int idUsuario, int idRetweet, int numeroCurtidas, int numeroRetweets);

    std::string Tweet::getTexto();

    static std::vector<Tweet> listarTweetsPorUsuario(int idUsuario);

};
#endif //CLASSESTWITTER_TWEET_H
