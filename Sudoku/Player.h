#pragma once
#include "Helper.h"

class Player
{
private:
	string username;
	int score;
public:
	Player();
	~Player() = default;
	void setUsername(string username);
	void setScore(int score);
	string getUsername();
	int getScore();
};
