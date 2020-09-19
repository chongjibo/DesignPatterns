//#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
class Resume
{
public:
	Resume(){}
	virtual ~Resume(){}
	virtual Resume* clone() = 0;
	virtual void set(char *n) {};
	virtual void show() {};

protected:
	char *name;
};
class ResumeA : public Resume
{
public:
	ResumeA(const char *str)
	{
		if (str == NULL) {
			name = new char[1];
			name[0] = '\0';
		}
		else {
			name = new char[strlen(str) + 1];
			strcpy(name, str);
		}
	}

	~ResumeA()
	{
		delete[]name;
	}

	 ResumeA(const ResumeA &r) {
		name = new char[strlen(r.name) + 1];
		strcpy(name, r.name);
	}

	ResumeA* clone()
	{
		//方式一
		ResumeA *a = new ResumeA(this->name);
		return a;
		//方式二
		//return new ResumeA(*this);
	}

	void set(char *n)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	virtual void show()
	{
		std::cout << "Resumen A" << std::endl;
	}
};
