#pragma once
#include <string>
#include <iostream>
#include <vector>
//透明组合模式
class Component
{
public:
	Component(){}
	Component(std::string iName)
		:_name(iName)
	{
	}

	virtual void add(Component*) = 0;
	virtual void remove(Component*) = 0;

	virtual Component *getChild(int) = 0;
	virtual void operation() = 0;

	std::string getName()
	{
		return _name;
	}

private:
	std::string _name;
};

//叶子构件
class Office : public Component
{
public:
	Office(std::string iName) : Component(iName)
	{
	}

	~Office(){}

	void add(Component* c)
	{
		std::cout << "not support add" << std::endl;
	}

	void remove(Component*)
	{
		std::cout << "not support remove" << std::endl;
	}

	Component *getChild(int)
	{
		std::cout << "not support getChild" << std::endl;
		return NULL;
	}
};

class AdminOffice : public Office
{
public:
	AdminOffice(std::string iName) : Office(iName)
	{

	}
	void operation()
	{
		std::cout << "AdminOffice operation:" << getName() <<  std::endl;
	}
};

class DeanOffice : public Office
{
public:
	DeanOffice(std::string iName) : Office(iName)
	{}

	void operation()
	{
		std::cout << "DeanOffice operation:" << getName() << std::endl;
	}
};

//容器构件
class SubComponent : public Component
{
public:
	SubComponent(std::string iName) : Component(iName)
	{
	}

	void add(Component *c)
	{
		componentList.push_back(c);
	}

	void remove(Component *c)
	{
		for (int i = 0; i < componentList.size(); ++i)
		{
			if (componentList[i]->getName() == c->getName())
			{
				componentList.erase(componentList.begin() + i);
				break;
			}
		}
	}

	Component *getChild(int i)
	{
		if (i < 0 || i > componentList.size())
			return NULL;

		return componentList[i];
	}

	void operation()
	{
		std::cout << "Component " << getName() << std::endl;
		for (int i = 0; i < componentList.size(); i++) {
			((Component*)componentList[i])->operation();
		}
	}

private:
	std::vector<Component *> componentList;
};