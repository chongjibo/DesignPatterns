#pragma once
#include <iostream>
//װ��ģʽ����
class DecoratorComponent
{
public:
	DecoratorComponent(){}
	virtual void operation() = 0;
};

//���幹����
class People : public DecoratorComponent
{
public:
	People(){}
	void operation()
	{
		std::cout << "��" << std::endl;
	}
};

//����װ����
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

//����
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
		std::cout << "���п�" << std::endl;
	}
};

//����
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
		std::cout << "������" << std::endl;
	}
};
//Ь
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
		std::cout << "��Ь��" << std::endl;
	}
};
