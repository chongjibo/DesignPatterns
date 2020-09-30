#pragma once
//ְ����ģʽ
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

//��������
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

//���崦���� �鳤
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
			std::cout << "�鳤" << getName() << "�����˸�Ʊ��" << std::endl;
			bill->print();
			std::cout << "\n" << std::endl;
		}
		else {
			std::cout << "�鳤��Ȩ����ת���ϼ�" << std::endl;
			this->superior->handleRequest(bill);
		}
	}
};

//����
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
			std::cout << "����" << getName() << "�����˸�Ʊ��" << std::endl;
			bill->print();
			std::cout << "\n" << std::endl;
		}
		else {
			std::cout << "������Ȩ����ת���ϼ�" << std::endl;
			this->superior->handleRequest(bill);
		}
	}
};

//����
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
			std::cout << "����" << getName() << "�����˸�Ʊ��" << std::endl;
			bill->print();
			std::cout << "\n" << std::endl;
		}
		else {
			std::cout << "������Ȩ����ת���ϼ�" << std::endl;
			this->superior->handleRequest(bill);
		}
	}
};

//���³�
class BOSS : public Approver
{
public:
	BOSS(std::string iName)
		:Approver(iName)
	{
	}

	void handleRequest(Bill *bill)
	{
		std::cout << "���³�" << getName() << "�����˸�Ʊ��" << std::endl;
		bill->print();	
		std::cout << "\n" << std::endl;
	}
};

