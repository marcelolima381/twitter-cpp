-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema twittercpp
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `twittercpp` ;

-- -----------------------------------------------------
-- Schema twittercpp
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `twittercpp` DEFAULT CHARACTER SET utf8 ;
USE `twittercpp` ;

-- -----------------------------------------------------
-- Table `twittercpp`.`users`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`users` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `account` VARCHAR(45) NOT NULL,
  `password` VARCHAR(45) NOT NULL,
  `profile` VARCHAR(45) NOT NULL,
  `name` VARCHAR(45) NULL DEFAULT NULL,
  `age` INT NULL DEFAULT NULL,
  `city` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`tweets`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`tweets` (
  `id` INT(11) NOT NULL,
  `details` DATE NULL DEFAULT NULL,
  `description` VARCHAR(140) NULL DEFAULT NULL,
  `users_id` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `users_id`),
  INDEX `fk_tweets_users1_idx` (`users_id` ASC),
  CONSTRAINT `fk_tweets_users1`
    FOREIGN KEY (`users_id`)
    REFERENCES `twittercpp`.`users` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`comments`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`comments` (
  `id` INT(11) NOT NULL,
  `description` VARCHAR(140) NULL DEFAULT NULL,
  `tweets_id` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `tweets_id`),
  INDEX `fk_comments_tweets1_idx` (`tweets_id` ASC),
  CONSTRAINT `fk_comments_tweets1`
    FOREIGN KEY (`tweets_id`)
    REFERENCES `twittercpp`.`tweets` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`comments_likes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`comments_likes` (
  `id` INT(11) NOT NULL,
  `users_id` INT(11) NOT NULL,
  `comments_id` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `users_id`, `comments_id`),
  INDEX `fk_comments_likes_users1_idx` (`users_id` ASC),
  INDEX `fk_comments_likes_comments1_idx` (`comments_id` ASC),
  CONSTRAINT `fk_comments_likes_comments1`
    FOREIGN KEY (`comments_id`)
    REFERENCES `twittercpp`.`comments` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_comments_likes_users1`
    FOREIGN KEY (`users_id`)
    REFERENCES `twittercpp`.`users` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`followee`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`followee` (
  `id` INT(11) NOT NULL,
  `follower` INT(11) NOT NULL,
  `following` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `follower`, `following`),
  INDEX `fk_followee_users1_idx` (`follower` ASC),
  INDEX `fk_followee_users2_idx` (`following` ASC),
  CONSTRAINT `fk_followee_users1`
    FOREIGN KEY (`follower`)
    REFERENCES `twittercpp`.`users` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_followee_users2`
    FOREIGN KEY (`following`)
    REFERENCES `twittercpp`.`users` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`hashtags`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`hashtags` (
  `id` INT(11) NOT NULL,
  `name` VARCHAR(45) NULL DEFAULT NULL,
  `tweets_id` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `tweets_id`),
  INDEX `fk_hashtags_tweets1_idx` (`tweets_id` ASC),
  CONSTRAINT `fk_hashtags_tweets1`
    FOREIGN KEY (`tweets_id`)
    REFERENCES `twittercpp`.`tweets` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`tweets_likes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`tweets_likes` (
  `id` INT(11) NOT NULL,
  `tweets_id` INT(11) NOT NULL,
  `users_id` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `tweets_id`, `users_id`),
  INDEX `fk_tweets_likes_tweets_idx` (`tweets_id` ASC),
  INDEX `fk_tweets_likes_users1_idx` (`users_id` ASC),
  CONSTRAINT `fk_tweets_likes_tweets`
    FOREIGN KEY (`tweets_id`)
    REFERENCES `twittercpp`.`tweets` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_tweets_likes_users1`
    FOREIGN KEY (`users_id`)
    REFERENCES `twittercpp`.`users` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `twittercpp`.`usertags`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twittercpp`.`usertags` (
  `id` INT(11) NOT NULL,
  `name` VARCHAR(45) NULL DEFAULT NULL,
  `tweets_id` INT(11) NOT NULL,
  PRIMARY KEY (`id`, `tweets_id`),
  INDEX `fk_usertags_tweets1_idx` (`tweets_id` ASC),
  CONSTRAINT `fk_usertags_tweets1`
    FOREIGN KEY (`tweets_id`)
    REFERENCES `twittercpp`.`tweets` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
