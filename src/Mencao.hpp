//
// Created by Mihawk on 09/10/2018.
//

#ifndef CLASSESTWITTER_MENCAO_HPP
#define CLASSESTWITTER_MENCAO_HPP
#include <iostream>

class Mencao {
private:
    std::string idTweet;

public:
    const std::string &getIdTweet() const;

    void setIdTweet(const std::string &idTweet);

    Mencao(const std::string &idTweet);

};


#endif //CLASSESTWITTER_MENCAO_HPP
