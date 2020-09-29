#pragma once
#include <iostream>
//��ϵͳ
class Memory
{
public:
	Memory(){}
	void selfCheck() {
		std::cout << "�ڴ��Լ�" << std::endl;
	}
	
};

class CPU
{
public:
	CPU() {}
	void run() {
		std::cout << "����CPU" << std::endl;
	}
};

class HardDisk
{
public:
	HardDisk(){}
	void read() {
		std::cout << "��ȡӲ��" << std::endl;
	}
};

class OS
{
public:
	OS() {}
	void load() {
		std::cout << "�������ϵͳ" << std::endl;
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
		std::cout << "���ڿ�������" << std::endl;
		memory->selfCheck();
		cpu->run();
		hardDisk->read();
		os->load();
		std::cout << "������ɣ�" << std::endl;
	}

private:
	Memory *memory;
	CPU *cpu;
	HardDisk *hardDisk;
	OS *os;
};

