//
// Created by Mihawk on 09/10/2018.
//

#ifndef CLASSESTWITTER_FEED_HPP
#define CLASSESTWITTER_FEED_HPP
#include <iostream>

class Feed {
private:
    std::string idUsuario;
public:
    const std::string &getIdUsuario() const;

    void setIdUsuario(const std::string &idUsuario);

    Feed(const std::string &idUsuario);
};


#endif //CLASSESTWITTER_FEED_HPP
