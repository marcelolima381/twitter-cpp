//
// Created by pedro on 29/10/2018.
//

#include <vector>
#include "Tweet.h"

Tweet::Tweet(const std::string &texto, int id, int idUsuario, int idRetweet, int numeroCurtidas, int numeroRetweets) :
        texto(texto), id(id), idUsuario(idUsuario), idRetweet(idRetweet), numeroCurtidas(numeroCurtidas),
        numeroRetweets(numeroRetweets){};

std::string Tweet::getTexto(){
    return texto;
}

std::vector<Tweet> Tweet::listarTweetsPorUsuario(int idUsuario)
{
    //TODO: AQUI TEM QUE BUSCAR DO BANCO DE DADOS (Pedro)
    std::vector<Tweet> listaTweets;

    listaTweets.push_back(*(new Tweet("Tweet 1",1,idUsuario,0,100,20)));
    listaTweets.push_back(*(new Tweet("Tweet 2",2,idUsuario,0,200,40)));
    listaTweets.push_back(*(new Tweet("Tweet 3",3,idUsuario,0,300,60)));

    return listaTweets;
}