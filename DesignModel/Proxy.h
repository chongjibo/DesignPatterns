#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string>
//抽象主题
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
		std::cout << "调用业务方法" << std::endl;
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
		std::cout << std::string("方法method()被调用，调用时间为 ") << log->getTime() << std::endl;
	}

	void postCallMethod()
	{
		std::cout << "方法调用成功" << std::endl;
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

