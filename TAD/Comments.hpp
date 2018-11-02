//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_COMMENTS_HPP
#define INC_2018_2_GRUPO19_COMMENTS_HPP

#include <iostream>

class Comments {
private:
    int id;
    std::string description;
    int tweets_id;

public:
    int getId() const;

    void setId(int id);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    int getTweets_id() const;

    void setTweets_id(int tweets_id);

};


#endif //INC_2018_2_GRUPO19_COMMENTS_HPP
