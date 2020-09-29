#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <mutex>
//抽象享元类
class NetDevice
{
public:
	NetDevice(){}
	virtual std::string getName() = 0;

	void print(int port)
	{
		std::cout << getName() << " 端口：" << port << std::endl;
	}
};

//具体享元类
class Hub:public NetDevice
{
public:
	Hub(){}
	std::string getName()
	{
		return "集线器";
	}
};

//具体享元类
class Switch : public NetDevice
{
public:
	Switch(){}
	std::string getName()
	{
		return "交换机";
	}
};

//享元工厂类
class NetDeviceFactory
{
public:
	NetDevice *getNetDevice(char ch)
	{
		if (ch == 'S')
			return devicePool[1];
		else if (ch == 'H')
			return devicePool[0];
		else
			std::cout << "wrong input" << std::endl;

		return NULL;
	}

	static NetDeviceFactory* getInstance()
	{
		if (instance == NULL)
		{
			_mutex.lock();
			if (instance == NULL)
			{
				instance = new NetDeviceFactory();
			}
			_mutex.unlock();
		}
		return instance;
	}

private:
	NetDeviceFactory()
	{
		Hub *huber = new Hub();
		Switch *switcher = new Switch();
		devicePool.push_back(huber);
		devicePool.push_back(switcher);
	}

	static NetDeviceFactory *instance;
	static std::mutex _mutex;
	std::vector<NetDevice*> devicePool;  //共享池
};



