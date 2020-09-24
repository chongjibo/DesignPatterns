#pragma once
#include <iostream>
//装饰模式基类
class DecoratorComponent
{
public:
	DecoratorComponent(){}
	virtual void operation() = 0;
};

//具体构件类
class People : public DecoratorComponent
{
public:
	People(){}
	void operation()
	{
		std::cout << "人" << std::endl;
	}
};

//抽象装饰类
class Decorator : public DecoratorComponent
{
public:
	Decorator(){}
	Decorator(DecoratorComponent *c)
	{
		_component = c;
	}

	void operation()
	{
		_component->operation();
	}

	DecoratorComponent* getComponent()
	{
		return _component;
	}

	void setComponent(DecoratorComponent *c)
	{
		_component = c;
	}

private:
	DecoratorComponent *_component;
};

//上衣
class Jacket : public Decorator
{
public:
	Jacket(DecoratorComponent *c)
	{
		setComponent(c);
	}

	void operation()
	{
		this->getComponent()->operation();
		this->newOperation();
	}

	void newOperation()
	{
		std::cout << "穿夹克" << std::endl;
	}
};

//裤子
class Trousers : public Decorator
{
public:
	Trousers(DecoratorComponent *c)
	{
		setComponent(c);
	}

	void operation()
	{
		this->getComponent()->operation();
		this->newOperation();
	}

	void newOperation()
	{
		std::cout << "穿裤子" << std::endl;
	}
};
//鞋
class Shoe : public Decorator
{
public:
	Shoe(DecoratorComponent *c)
	{
		setComponent(c);
	}

	void operation()
	{
		this->getComponent()->operation();
		this->newOperation();
	}

	void newOperation()
	{
		std::cout << "穿鞋子" << std::endl;
	}
};
