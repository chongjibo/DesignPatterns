#pragma once
#include<iostream>
#include<vector>
//�����
class Lamp
{
public:
	Lamp():_lampState(false)
	{
		
	}

	void on()
	{
		_lampState = true;
		std::cout << "����" << std::endl;
	}

	void off()
	{
		_lampState = false;
		std::cout << "�ص�" << std::endl;
	}

	bool getLampState()
	{
		return _lampState;
	}

private:
	bool _lampState;
};

//����
class Fan
{
public:
	Fan():_fanState(false)
	{}
	void on()
	{
		_fanState = true;
		std::cout << "������" << std::endl;
	}
	void off()
	{
		_fanState = false;
		std::cout << "�ط���" << std::endl;
	}

	bool getFanState()
	{
		return _fanState;
	}
private:
	bool _fanState;
};
class Command
{
public:
	Command()
	{}
	virtual void execute() = 0;

private:
	Command *_command;
};

class LampCommand : public Command
{
public:
	LampCommand()
	{
		std::cout << "���ؿ��Ƶ��" << std::endl;
		_lamp = new Lamp;
	}

	void execute()
	{
		if (_lamp->getLampState())
		{
			_lamp->off();
		}
		else
		{
			_lamp->on();
		}
	}
private:
	Lamp *_lamp;
};

class FanCommand : public Command
{
public:
	FanCommand()
	{
		std::cout << "���ؿ��Ʒ���" << std::endl;
		_fan = new Fan;
	}

	void execute()
	{
		if (_fan->getFanState())
		{
			_fan->off();
		}
		else
		{
			_fan->on();
		}
	}
private:
	Fan *_fan;
};

class Button
{
public:
	Button()
	{
		
	}
	void setCommand(Command *cmd)
	{
		_cmd = cmd;
	}

	void touch()
	{
		std::cout << "��������:" << std::endl;
		_cmd->execute();
	}

private:
	Command *_cmd;
};

class CommandQueue
{
public:
	CommandQueue()
	{}
	void addCommand(Command *cmd)
	{
		_commandQueue.push_back(cmd);
	}

	void execute()
	{
		for (int i = 0; i < _commandQueue.size(); i++)
		{
			_commandQueue[i]->execute();
		}
	}
private:
	std::vector<Command*> _commandQueue;
};

class Button2
{
public:
	Button2()
	{}

	void setCommandQueue(CommandQueue *cmdQueue)
	{
		_cmdQueue = cmdQueue;
	}

	void touch()
	{
		std::cout << "��������" << std::endl;
		_cmdQueue->execute();
	}

private:
	CommandQueue *_cmdQueue;
};