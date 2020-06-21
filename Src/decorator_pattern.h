#pragma once

#include <iostream>

namespace FjhApp {

// 首先是爱照镜子的女人
class IWomen
{
public:
	virtual void lookIntoTheMirror() = 0;
};

// 然后老婆是个爱照镜子的喜欢打扮的女人（具体需要装饰对象）
class Wife : public IWomen
{
public:
	void lookIntoTheMirror()
	{
		std::cout << "镜子中的老婆";
	}
};

// 需要一个化妆的女人（装饰品的抽象基类）
class DecoratorWomen : public IWomen
{
public:
	DecoratorWomen(IWomen* woman) : m_women(woman)
	{
        std::cout << "装饰品的抽象基类构造函数" << std::endl;
	}

	void lookIntoTheMirror()
	{
		m_women->lookIntoTheMirror();
		makeUp();
	}
	virtual void makeUp() = 0; //化妆

protected:
	IWomen* m_women;
};

// 下面是具体3种用于化妆的化妆品： 口红，睫毛膏，香水
class Lipstick : public DecoratorWomen
{
public:
	Lipstick(IWomen* woman):DecoratorWomen(woman)
    {
        std::cout << "装饰品-口红的构造函数" << std::endl;
    }
	void makeUp()
	{
		std::cout <<"有火红的嘴唇！";
	}
};

class Mascara : public DecoratorWomen
{
public:
	Mascara(IWomen* woman):DecoratorWomen(woman)
    {
        std::cout << "装饰品-睫毛膏构造函数" << std::endl;
    }
	void makeUp()
	{
		std::cout <<"有黑黑的睫毛！";
	}
};

class Perfume : public DecoratorWomen
{
public:
	Perfume(IWomen* woman):DecoratorWomen(woman)
    {
            
    }
	void makeUp()
	{
		std::cout << "有香奈儿的味道！";
	}
};

} // FjhApp

// 测试用例如下:
// #include "Src/decorator_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
    
//     FjhApp::IWomen *myWife = new FjhApp::Wife();
//     FjhApp::Lipstick *lips  = new FjhApp::Lipstick(myWife);
//     FjhApp::Mascara *mas = new FjhApp::Mascara(lips);
//     FjhApp::Perfume *per = new FjhApp::Perfume(mas);

//     myWife = per;
//     myWife->lookIntoTheMirror();
    
//     return 0;
// }

// 输出
// 设计模式测试用例
// 装饰品的抽象基类构造函数
// 装饰品-口红的构造函数
// 装饰品的抽象基类构造函数
// 装饰品-睫毛膏构造函数
// 装饰品的抽象基类构造函数
// 镜子中的老婆有火红的嘴唇！有黑黑的睫毛！有香奈儿的味道！
