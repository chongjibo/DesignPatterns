#pragma once
#include <iostream>
#include <mutex>
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (instance == NULL)
		{
			s_mutex.lock();
			if (instance == NULL)
			{
				instance = new Singleton;
			}
			s_mutex.unlock();
		}

		return instance;
	}

private:
	Singleton(){}
	static Singleton* instance;
	static std::mutex s_mutex;
};

Singleton* Singleton::instance = NULL;
std::mutex Singleton::s_mutex;

