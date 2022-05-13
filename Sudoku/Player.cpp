#include "Player.h"

Player::Player()
{
	username = "";
	score = 0;
}

void Player::setUsername(string username)
{
	this->username = username;
}

void Player::setScore(int score)
{
	this->score = score;
}

string Player::getUsername()
{
	return username;
}

int Player::getScore()
{
	return score;
}