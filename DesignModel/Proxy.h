#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string>
//��������
class Subject
{
public:
	Subject(){}
	virtual void method() = 0;
};

class RealSubject : public Subject
{
public:
	RealSubject(){}
	void method()
	{
		std::cout << "����ҵ�񷽷�" << std::endl;
	}

};

class Log
{
public:
	Log(){}
	std::string getTime()
	{
		time_t t = time(NULL);
		char ch[64] = { 0 };
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
		return ch;
	}
};

class Proxy : public Subject
{
public:
	Proxy()
	{
		realSubject = new RealSubject();
		log = new Log();
	}

	void preCallMethod()
	{
		std::cout << std::string("����method()�����ã�����ʱ��Ϊ ") << log->getTime() << std::endl;
	}

	void postCallMethod()
	{
		std::cout << "�������óɹ�" << std::endl;
	}

	void method()
	{
		preCallMethod();
		realSubject->method();
		postCallMethod();
	}

private:
	RealSubject *realSubject;
	Log *log;
};

