#pragma once
#include <vector>
#include <string>
#include <iostream>

class Iterator;
class Remotecontrol;

//抽象聚合类
class Aggregate
{
public:
	Aggregate() {}
	virtual Iterator* createIterator() = 0;
};

//具体聚合类
class Television : public Aggregate
{
public:
	Television(){}
	Television(std::vector<std::string> iChannelList);
	Iterator *createIterator();
	//获取总频道数
	int getTotalChannelNum();
	void play(int i);

private:
	std::vector<std::string> channelList;
};

class Iterator
{
public:
	Iterator(){}
	virtual void first() = 0;
	virtual void last() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool hasNext() = 0;
	virtual bool hasPrevious() = 0;
	virtual void currentChannel() = 0;
};

class Remotecontrol : public Iterator
{
public:
	Remotecontrol() {}
	void setTV(Television* iTv)
	{
		tv = iTv;
		cursor = -1;
		totalNum = tv->getTotalChannelNum();
	}

	virtual void first()
	{
		cursor = 0;
	}

	virtual void last()
	{
		cursor = totalNum - 1;
	}

	virtual void next()
	{
		if(cursor < totalNum)
			++cursor;
	}

	virtual void previous()
	{
		if (cursor > -1)
			--cursor;
	}

	virtual bool hasNext() 
	{
		return !(cursor == totalNum);
	}

	virtual bool hasPrevious()
	{
		return !(cursor == -1);
	}

	void currentChannel()
	{
		tv->play(cursor);
	}

private:
	//游标
	int cursor;
	//总频道数
	int totalNum;
	//电视
	Television *tv;
};
