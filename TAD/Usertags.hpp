//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_USERTAGS_HPP
#define INC_2018_2_GRUPO19_USERTAGS_HPP

#include <iostream>

class Usertags {
private:
    int id;
    std::string name;
    int tweets_id;

public:
    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getTweets_id() const;

    void setTweets_id(int tweets_id);
};

#endif //INC_2018_2_GRUPO19_USERTAGS_HPP
