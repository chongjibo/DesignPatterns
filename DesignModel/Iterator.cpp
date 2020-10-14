#include "Iterator.h"

Television::Television(std::vector<std::string> iChannelList)
{
	this->channelList = iChannelList;
}

Iterator * Television::createIterator()
{
	Remotecontrol *remotecontrol = new Remotecontrol();
	remotecontrol->setTV(this);
	return remotecontrol;
}

int Television::getTotalChannelNum()
{
	return channelList.size();
}

void Television::play(int i)
{
	std::cout << "�������ڲ��ŵ���" << channelList.at(i) << std::endl;
}
