#pragma once
#include <iostream>
class Game
{
public:
	Game(){}
	virtual void play() = 0;

private:
};

class GameA : public Game
{
public:
	GameA(){}
	void play()
	{
		std::cout << "Play A" << std::endl;
	}
};

class GameB : public Game
{
public:
	GameB() {}
	void play()
	{
		std::cout << "Play B" << std::endl;
	}
};

class Phone 
{
public:
	Phone() {}
	virtual void setupGame(Game *igame) = 0;
	virtual void play() = 0;

private:
	Game *_game;  //¿ÉÊ¡ÂÔ
};

class PhoneA : public Phone
{
public:
	PhoneA(){}
	void setupGame(Game *igame)
	{
		this->_game = igame;
	}

	void play()
	{
		this->_game->play();
	}

private:
	Game *_game;
};

class PhoneB : public Phone
{
public:
	PhoneB() {}
	void setupGame(Game *igame)
	{
		this->_game = igame;
	}

	void play()
	{
		this->_game->play();
	}

private:
	Game *_game;
};