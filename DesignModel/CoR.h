#pragma once
//职责链模式
#include <string>
#include <iostream>
class Bill
{
public:
	Bill(int iId, std::string iName, double iAccount)
	{
		id = iId;
		name = iName;
		account = iAccount;
	}

	double getAccount()
	{
		return account;
	}
	void print()
	{
		std::cout << "ID " << id << std::endl;
		std::cout << "name " << name << std::endl;
		std::cout << "account " << account << std::endl;
	}
private:
	int id;
	std::string name;
	double account;
};

//抽象处理者
class Approver
{
public:
	Approver(std::string iName)
	{
		setName(iName);
	}

	void setName(std::string iName)
	{
		name = iName;
	}

	std::string getName()
	{
		return name;
	}

	void setSuperior(Approver *superior)
	{
		this->superior = superior;
	}

	virtual void handleRequest(Bill *) = 0;

protected:
	Approver *superior;
private:
	std::string name;
};

//具体处理者 组长
class GroupLeader : public Approver
{
public:
	GroupLeader(std::string iName)
	:Approver(iName)
	{
	}

	void handleRequest(Bill *bill)
	{
		if (bill->getAccount() < 10)
		{
			std::cout << "组长" << getName() << "处理了该票据" << std::endl;
			bill->print();
			std::cout << "\n" << std::endl;
		}
		else {
			std::cout << "组长无权处理，转交上级" << std::endl;
			this->superior->handleRequest(bill);
		}
	}
};

//主管
class Head : public Approver
{
public:
	Head(std::string iName)
		:Approver(iName)
	{
	}

	void handleRequest(Bill *bill)
	{
		if (bill->getAccount() >= 10 && bill->getAccount() < 30)
		{
			std::cout << "主管" << getName() << "处理了该票据" << std::endl;
			bill->print();
			std::cout << "\n" << std::endl;
		}
		else {
			std::cout << "主管无权处理，转交上级" << std::endl;
			this->superior->handleRequest(bill);
		}
	}
};

//经理
class Manager : public Approver
{
public:
	Manager(std::string iName)
		:Approver(iName)
	{
	}

	void handleRequest(Bill *bill)
	{
		if (bill->getAccount() >= 30 && bill->getAccount() < 60)
		{
			std::cout << "经理" << getName() << "处理了该票据" << std::endl;
			bill->print();
			std::cout << "\n" << std::endl;
		}
		else {
			std::cout << "经理无权处理，转交上级" << std::endl;
			this->superior->handleRequest(bill);
		}
	}
};

//董事长
class BOSS : public Approver
{
public:
	BOSS(std::string iName)
		:Approver(iName)
	{
	}

	void handleRequest(Bill *bill)
	{
		std::cout << "董事长" << getName() << "处理了该票据" << std::endl;
		bill->print();	
		std::cout << "\n" << std::endl;
	}
};

