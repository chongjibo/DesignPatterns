#pragma once
#include<iostream>
#include<vector>
//电灯类
class Lamp
{
public:
	Lamp():_lampState(false)
	{
		
	}

	void on()
	{
		_lampState = true;
		std::cout << "开灯" << std::endl;
	}

	void off()
	{
		_lampState = false;
		std::cout << "关灯" << std::endl;
	}

	bool getLampState()
	{
		return _lampState;
	}

private:
	bool _lampState;
};

//风扇
class Fan
{
public:
	Fan():_fanState(false)
	{}
	void on()
	{
		_fanState = true;
		std::cout << "开风扇" << std::endl;
	}
	void off()
	{
		_fanState = false;
		std::cout << "关风扇" << std::endl;
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
		std::cout << "开关控制电灯" << std::endl;
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
		std::cout << "开关控制风扇" << std::endl;
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
		std::cout << "触摸开关:" << std::endl;
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
		std::cout << "触摸开关" << std::endl;
		_cmdQueue->execute();
	}

private:
	CommandQueue *_cmdQueue;
};