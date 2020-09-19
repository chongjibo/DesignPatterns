#pragma once
#include <string>
//
class Meal
{
public:
	void setDrink(std::string drink)
	{
		_drink = drink;
	}

	std::string getDrink()
	{
		return _drink;
	}

	void setFood(std::string food)
	{
		_food = food;
	}

	std::string getFood()
	{
		return _food;
	}

private:
	std::string _drink;
	std::string _food;
};


class Builder
{
public:
	Builder()
	{
		_meal = new Meal();
	}

	virtual void buildFoot() = 0;
	virtual void buildDrink() = 0;

	Meal* getMeal()
	{
		return _meal;
	}
protected:
	Meal *_meal;
};

class KFCBuilder : public Builder
{
public:
	void buildFoot()
	{
		_meal->setFood("����");
	}

	void buildDrink()
	{
		_meal->setDrink("����");
	}
};

class HLSBuilder : public Builder
{
public:
	void buildFoot()
	{
		_meal->setFood("�����");
	}

	void buildDrink()
	{
		_meal->setDrink("�̲�");
	}
};

class Director
{
public:
	void setBuilder(Builder *builder)
	{
		_builder = builder;
	}

	Meal *construct()
	{
		_builder->buildDrink();
		_builder->buildFoot();

		return _builder->getMeal();
	}
private:
	Builder *_builder;
};