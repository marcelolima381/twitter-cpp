cmake_minimum_required(VERSION 3.12)
project(2018_2_grupo19)

set(CMAKE_CXX_STANDARD 11)

add_executable(2018_2_grupo19 main.cpp TAD/Comments.cpp TAD/Comments.hpp TAD/Tweet.cpp TAD/Tweet.hpp TAD/Tweets_likes.cpp TAD/Tweets_likes.hpp TAD/Users.cpp TAD/Users.hpp Interface/AbstractInterface.cpp Interface/AbstractInterface.hpp Interface/Login.cpp Interface/Login.hpp TAD/AbstractConnection.cpp TAD/AbstractConnection.hpp Sessao/Session.cpp Sessao/Session.hpp Interface/Feed.cpp Interface/Feed.hpp Interface/ListComments.cpp Interface/ListComments.hpp Interface/Perfil.cpp Interface/Perfil.hpp Interface/Pesquisa.cpp Interface/Pesquisa.hpp)
target_link_libraries(2018_2_grupo19 mysqlcppconn)