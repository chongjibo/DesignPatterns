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
	std::cout << "房东查看租客信息" << std::endl;
	this->getMediator()->operation(this);
}

void Landlord::answer()
{
	std::cout << "房东姓名：" << name << " 房租：" << price << " 地址：" << address << "联系电话：" << phoneNumber << std::endl;
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
	std::cout << "租客查看房东信息" << std::endl;
	this->getMediator()->operation(this);
}

void Tenant::answer()
{
	std::cout << "租客姓名" << name << std::endl;
}
