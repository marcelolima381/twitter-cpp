//
// Created by marcelo on 02/11/18.
//

#ifndef INC_2018_2_GRUPO19_COMMENTS_LIKES_HPP
#define INC_2018_2_GRUPO19_COMMENTS_LIKES_HPP

#include <iostream>

class Comments_likes {
 private:
	int id;
	int users_id;
	int comments_id;

 public:
	int getId() const;

	void setId(int id);

	int getUsers_id() const;

	void setUsers_id(int users_id);

	int getComments_id() const;

	void setComments_id(int comments_id);

};

#endif //INC_2018_2_GRUPO19_COMMENTS_LIKES_HPP
