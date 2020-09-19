#pragma once
#include <stdio.h>
#include <string>
class AbstractorProduct
{
public:
	AbstractorProduct() {

	};

	virtual void printName()
	{
		printf("Jungle get AbstractorProduct\n");
	}
	virtual void play()
	{
		printf("Jungle play AbstractorProduct\n");
	}
};

class Basketball : public AbstractorProduct
{
public:
	Basketball() 
	{
		printName();
		play();
	}
	//具体实现方法
	void printName() {
		printf("Jungle get Basketball\n");
	}
	void play() {
		printf("Jungle play Basketball\n");
	}
};

//具体产品类Football
class Football :public AbstractorProduct
{
public:
	Football() {
		printName();
		play();
	}
	//具体实现方法
	void printName() {
		printf("Jungle get Football\n");
	}
	void play() {
		printf("Jungle play Football\n");
	}
};

//具体产品类Volleyball
class Volleyball :public AbstractorProduct
{
public:
	Volleyball() {
		printName();
		play();
	}
	//具体实现方法
	void printName() {
		printf("Jungle get Volleyball\n");
	}
	void play() {
		printf("Jungle play Volleyball\n");
	}
};

//简单工厂模式
class Factory
{
public:
	AbstractorProduct* getSportProduct(std::string productName)
	{
		AbstractorProduct *pro = NULL;
		if (productName == "basketball")
		{
			pro = new Basketball();
		}
		else if (productName == "Football")
		{
			pro = new Football();
		}
		else {
			pro = new Volleyball();
		}

		return pro;
	}
};


//工厂方法模式
class AbstractFactory {
public:
	virtual AbstractorProduct* getPro() = 0;
};

class FootballFactory : public AbstractFactory{
public:
	FootballFactory()
	{
		printf("FootballFactory\n");
	}

	AbstractorProduct* getPro()
	{
		return new Football();
	}
};


class BasketFactory : public AbstractFactory {
public:
	BasketFactory()
	{
		printf("BasketballFactory\n");
	}

	AbstractorProduct* getPro()
	{
		return new Basketball();
	}
};

class VolleyballFactory : public AbstractFactory {
public:
	VolleyballFactory()
	{
		printf("VolleyballFactory\n");
	}

	AbstractorProduct* getPro()
	{
		return new Volleyball();
	}
};