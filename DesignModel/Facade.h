#pragma once
#include <iostream>
//子系统
class Memory
{
public:
	Memory(){}
	void selfCheck() {
		std::cout << "内存自检" << std::endl;
	}
	
};

class CPU
{
public:
	CPU() {}
	void run() {
		std::cout << "运行CPU" << std::endl;
	}
};

class HardDisk
{
public:
	HardDisk(){}
	void read() {
		std::cout << "读取硬盘" << std::endl;
	}
};

class OS
{
public:
	OS() {}
	void load() {
		std::cout << "载入操作系统" << std::endl;
	}
};

class Facade
{
public:
	Facade()
	{
		memory = new Memory();
		cpu = new CPU();
		hardDisk = new HardDisk();
		os = new OS();
	}

	void powerOn()
	{
		std::cout << "正在开机……" << std::endl;
		memory->selfCheck();
		cpu->run();
		hardDisk->read();
		os->load();
		std::cout << "开机完成！" << std::endl;
	}

private:
	Memory *memory;
	CPU *cpu;
	HardDisk *hardDisk;
	OS *os;
};

