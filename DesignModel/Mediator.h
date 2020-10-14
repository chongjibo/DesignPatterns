#pragma once
#include <iostream>
#include <vector>
#include <string>
enum PERSON_TYPE
{
	NONE_PERSON,
	LANDLORD,
	TENANT
};

class Mediator;
class Landlord;
class Tenant;

//抽象同事类
class Colleague
{
public:
	Colleague(){}
	void setMediator(Mediator *iMediator) 
	{
		this->mediator = iMediator;
	}

	Mediator* getMediator()
	{
		return mediator;
	}

	void setPersonType(PERSON_TYPE ipersonType)
	{
		personType = ipersonType;
	}

	PERSON_TYPE getPersonType()
	{
		return personType;
	}
	virtual void ask() = 0;
	virtual void answer() = 0;
private:
	PERSON_TYPE personType;
	Mediator *mediator;
};

//具体同事类——房东
class Landlord : public Colleague
{
public:
	Landlord();
	Landlord(std::string iName, int iPrice, std::string iAddress, std::string iPhoneNum);
	void ask();
	void answer();

private:
	std::string name;
	int price;
	std::string address;
	std::string phoneNumber;
};

// 具体同事类：租客
class Tenant :public Colleague
{
public:
	Tenant();
	Tenant(std::string name);
	void ask();
	void answer();
private:
	std::string name;
};

class Mediator
{
public:
	Mediator() {}
	//声明抽象方法
	virtual void operation(Colleague *) = 0;
	//声明注册方法
	virtual void registerMethod(Colleague *) = 0;
};

class Agency : public Mediator
{
public:
	Agency() {}
	void registerMethod(Colleague *person)
	{
		switch (person->getPersonType())
		{
		case LANDLORD:
			landlordList.push_back((Landlord*)person);
			break;
		case TENANT:
			tenantList.push_back((Tenant*)person);
			break;
		default:
			std::cout << "wrong person" << std::endl;
		}
	}

	void operation(Colleague *person)
	{
		switch (person->getPersonType())
		{
		case LANDLORD:
			for (int i = 0; i < tenantList.size(); ++i)
			{
				tenantList[i]->answer();
			}
			break;
		case TENANT:
			for (int i = 0; i < landlordList.size(); ++i)
			{
				landlordList[i]->answer();
			}
			break;
		default:
			break;
		}
	}

private:
	std::vector<Landlord*> landlordList;
	std::vector<Tenant*> tenantList;
};