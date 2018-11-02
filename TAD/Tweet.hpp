//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_TWEET_HPP
#define INC_2018_2_GRUPO19_TWEET_HPP

#include <iostream>

class Tweet {
private:
    int id;
    std::string details;
    std::string description;
    int user_id;

public:
    int getId() const;

    void setId(int id);

    const std::string &getDetails() const;

    void setDetails(const std::string &details);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    int getUser_id() const;

    void setUser_id(int user_id);

};


#endif //INC_2018_2_GRUPO19_TWEET_HPP
