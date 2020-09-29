
// DesignModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include "Factory.h"
#include "BuilderModel.h"
#include "Prototype.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Flyweight.h"
#include "Proxy.h"

//工厂模式
void testFactory()
{
	AbstractorProduct *pro = NULL;
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
	proF = facF->getPro();
}

//建造者模式
void testBuilder()
{
	Builder *kfcBuilder = new KFCBuilder;
	Builder *hlsBuilder = new HLSBuilder;

	Director *director = new Director;
	director->setBuilder(kfcBuilder);
	Meal *kfcMeal = director->construct();
	std::cout << "KFCMeal : " << kfcMeal->getDrink() << kfcMeal->getFood() << std::endl;

	director->setBuilder(hlsBuilder);
	Meal *hlsMeal = director->construct();
	std::cout << "HLSMeal : " << hlsMeal->getDrink() << hlsMeal->getFood() << std::endl;
}

//原型模式
void testPrototype()
{
	ResumeA *resumeA = new ResumeA("ResumeAA");
	resumeA->show();

	Resume *resumeAA = resumeA->clone();
	resumeAA->show();
}

//适配器模式
void testAdapter()
{
	Duck *duck = new ClassAdapter();
	duck->quack();
	duck->fly();
}

//桥接模式
void testBridge()
{
	//A手机玩游戏A
	Phone *phoneA = new PhoneA();
	Game *game = new GameA();

	phoneA->setupGame(game);
	phoneA->play();

	delete game;

	//用A手机玩游戏B
	game = new GameB;
	phoneA->setupGame(game);
	phoneA->play();
}

//组合模式
void composite()
{

	Component *head, *sichuanBranch, *cdBranch, *myBranch, *office1, *office2, *office3,
		*office4, *office5, *office6, *office7, *office8;

	head = new SubComponent("总部");
	sichuanBranch = new SubComponent("四川分部");
	office1 = new AdminOffice("行政办公室");
	office2 = new DeanOffice("教务办公室");

	cdBranch = new SubComponent("成都分部");
	myBranch = new SubComponent("绵阳分部");
	office3 = new AdminOffice("行政办公室");
	office4 = new DeanOffice("教务办公室");

	office5 = new AdminOffice("行政办公室");
	office6 = new DeanOffice("教务办公室");

	office7 = new AdminOffice("行政办公室");
	office8 = new DeanOffice("教务办公室");

	cdBranch->add(office5);
	cdBranch->add(office6);

	myBranch->add(office7);
	myBranch->add(office8);

	sichuanBranch->add(office3);
	sichuanBranch->add(office4);
	sichuanBranch->add(cdBranch);
	sichuanBranch->add(myBranch);

	head->add(office1);
	head->add(office2);
	head->add(sichuanBranch);

	head->operation();
}

void testDecorator()
{
	//A穿上衣
	People *a = new People;
	Jacket *aJ = new Jacket(a);
	aJ->operation();

	//B穿上衣与裤子
	People *b = new People;
	Jacket *bJ = new Jacket(b);
	Trousers *bT = new Trousers(bJ);
	bT->operation();

	//C穿上衣、裤子、鞋子
	People *c = new People;
	Jacket *cJ = new Jacket(c);
	Trousers *cT = new Trousers(cJ);
	Shoe *cS = new Shoe(cT);
	cS->operation();
}

void testFacade()
{
	Facade *facade = new Facade;
	facade->powerOn();
}

void testFlyweight()
{
	NetDeviceFactory *factory = NetDeviceFactory::getInstance();

	NetDevice *device1, *device2, *device3, *device4;

	// 客户端1获取一个hub
	device1 = factory->getNetDevice('H');
	device1->print(1);
	// 客户端2获取一个hub
	device2 = factory->getNetDevice('H');
	device2->print(2);
	// 判断两个hub是否是同一个
	//printf("判断两个hub是否是同一个:\n");
	//printf("device1:%p\ndevice2:%p\n", device1, device2);

	// 客户端3获取一个switch
	device3 = factory->getNetDevice('S');
	device3->print(3);
	// 客户端4获取一个switch
	device4 = factory->getNetDevice('S');
	device4->print(4);
	// 判断两个switch是否是同一个
	//printf("判断两个switch是否是同一个:\n");
	//printf("device3:%p\ndevice4:%p\n", device3, device4);
}

void testProxy()
{
	Proxy *proxy = new Proxy;
	proxy->method();
}

int main()
{
	testProxy();
	//testFlyweight();
	//testFacade();
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
