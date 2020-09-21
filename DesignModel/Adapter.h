#pragma once
#include <iostream>
/*-------------------对象适配器--------------------*/
//鸭子类
class Duck 
{
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck :public Duck
{
public:
	void quack()
	{
		std::cout << "Quack" << std::endl;
	}
	void fly()
	{
		std::cout << "Fly" << std::endl;
	}
};

//火鸡类
class Turkey
{
public:
	virtual void gobble() = 0;   //此方法跟鸭子不一样
	virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
	void gobble()  //此方法跟鸭子不一样
	{
		std::cout << "Gobble" << std::endl;
	}

	void fly()
	{
		std::cout << "Fly short" << std::endl;
	}
};

class TurkeyAdapter : public Duck
{
public:
	TurkeyAdapter(WildTurkey *turkey)
	{
		_turkey = turkey;
	}

	void quack()
	{
		_turkey->gobble();
	}

	void fly()
	{
		_turkey->fly();
	}
private:
	WildTurkey *_turkey;
};

/*---------------类适配器-----------------*/
class ClassAdapter : public Duck, WildTurkey
{
public:
	void quack()
	{
		WildTurkey::gobble();
	}

	void fly()
	{
		WildTurkey::fly();
	}
};

