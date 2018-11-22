DROP SCHEMA IF EXISTS `twittercpp` ;

CREATE SCHEMA IF NOT EXISTS `twittercpp` DEFAULT CHARACTER SET utf8 ;
USE `twittercpp` ;

create table if not exists users
(
  id       int auto_increment
    primary key,
  account  varchar(45) not null,
  password varchar(45) not null,
  profile  varchar(45) not null,
  name     varchar(45) null,
  age      int         null,
  city     varchar(45) null
);

create table if not exists followee
(
  id        int auto_increment,
  follower  int not null,
  following int not null,
  primary key (id, follower, following),
  constraint fk_followee_users1
  foreign key (follower) references users (id),
  constraint fk_followee_users2
  foreign key (following) references users (id)
);

create index fk_followee_users1_idx
  on followee (follower);

create index fk_followee_users2_idx
  on followee (following);

create table if not exists tweets
(
  id          int auto_increment,
  description varchar(140) null,
  users_id    int          not null,
  data        datetime     null,
  primary key (id, users_id),
  constraint fk_tweets_users1
  foreign key (users_id) references users (id)
);

create table if not exists comments
(
  id          int auto_increment,
  description varchar(140) null,
  tweets_id   int          not null,
  users_id    int          null,
  primary key (id, tweets_id),
  constraint fk_comments_tweets1
  foreign key (tweets_id) references tweets (id),
  constraint fk_user_id_comment
  foreign key (users_id) references users (id)
);

create index fk_comments_tweets1_idx
  on comments (tweets_id);

create index fk_tweets_users1_idx
  on tweets (users_id);

create table if not exists tweets_likes
(
  id        int auto_increment,
  tweets_id int not null,
  users_id  int not null,
  primary key (id, tweets_id, users_id),
  constraint fk_tweets_likes_tweets
  foreign key (tweets_id) references tweets (id),
  constraint fk_tweets_likes_users1
  foreign key (users_id) references users (id)
);

create index fk_tweets_likes_tweets_idx
  on tweets_likes (tweets_id);

create index fk_tweets_likes_users1_idx
  on tweets_likes (users_id);


