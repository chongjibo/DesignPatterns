#pragma once
#include <iostream>
/*-------------------����������--------------------*/
//Ѽ����
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

//����
class Turkey
{
public:
	virtual void gobble() = 0;   //�˷�����Ѽ�Ӳ�һ��
	virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
	void gobble()  //�˷�����Ѽ�Ӳ�һ��
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

/*---------------��������-----------------*/
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

