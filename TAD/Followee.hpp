//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_FOLLOWEE_HPP
#define INC_2018_2_GRUPO19_FOLLOWEE_HPP


#include <iostream>

class Followee {
    int id;
    int follower;
    int following;

public:
    int getId() const;

    void setId(int id);

    int getFollower() const;

    void setFollower(int follower);

    int getFollowing() const;

    void setFollowing(int following);
};



#endif //INC_2018_2_GRUPO19_FOLLOWEE_HPP
