
// DesignModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include "Factory.h"
#include "BuilderModel.h"
#include "Prototype.h"
#include "Adapter.h"

int main()
{
	//工厂模式
	/*AbstractorProduct *pro = NULL;
	Factory *fac = new Factory;
	pro = fac->getSportProduct("Basketball");
	pro = fac->getSportProduct("Football");
	pro = fac->getSportProduct("Volleyball");

	AbstractorProduct *proF = NULL;
	AbstractFactory *facF = NULL;

	facF = new BasketFactory;
	proF = facF->getPro();

	facF = new FootballFactory;
	proF = facF->getPro();

	facF = new VolleyballFactory;
	proF = facF->getPro();*/

	//建造者模式
	/*Builder *kfcBuilder = new KFCBuilder;
	Builder *hlsBuilder = new HLSBuilder;

	Director *director = new Director;
	director->setBuilder(kfcBuilder);
	Meal *kfcMeal = director->construct();
	std::cout << "KFCMeal : " << kfcMeal->getDrink() << kfcMeal->getFood() << std::endl;

	director->setBuilder(hlsBuilder);
	Meal *hlsMeal = director->construct();
	std::cout << "HLSMeal : " << hlsMeal->getDrink() << hlsMeal->getFood() << std::endl;*/

	//原型模式
	/*ResumeA *resumeA = new ResumeA("ResumeAA");
	resumeA->show();

	Resume *resumeAA = resumeA->clone();
	resumeAA->show();*/

	//适配器模式
	Duck *duck = new ClassAdapter();
	duck->quack();
	duck->fly();


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
