#include "Mediator.h"

Landlord::Landlord()
	:name("none"), price(0), address("none"),phoneNumber("none")
{
	setPersonType(NONE_PERSON);
}

Landlord::Landlord(std::string iName, int iPrice, std::string iAddress, std::string iPhoneNum)
	:name(iName), price(iPrice), address(iAddress), phoneNumber(iPhoneNum)
{
	setPersonType(LANDLORD);
}

void Landlord::ask()
{
	std::cout << "�����鿴�����Ϣ" << std::endl;
	this->getMediator()->operation(this);
}

void Landlord::answer()
{
	std::cout << "����������" << name << " ���⣺" << price << " ��ַ��" << address << "��ϵ�绰��" << phoneNumber << std::endl;
}

Tenant::Tenant()
	:name("none")
{
	setPersonType(NONE_PERSON);
}

Tenant::Tenant(std::string iName)
	:name(iName)
{
	setPersonType(TENANT);
}

void Tenant::ask()
{
	std::cout << "��Ͳ鿴������Ϣ" << std::endl;
	this->getMediator()->operation(this);
}

void Tenant::answer()
{
	std::cout << "�������" << name << std::endl;
}
