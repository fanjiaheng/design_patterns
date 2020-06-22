#pragma once

#include <iostream>

// 懒汉式单例模式：在类加载时不初始化、按照需求创建实例

namespace FjhApp {
class CSingletonPatternLazyMan
{
public:
    void sayHello(void);

    static CSingletonPatternLazyMan* getInstrance()
    {
        if (NULL == instrance)
		{
			instrance = new CSingletonPatternLazyMan();
			std::cout << "懒汉模式对象创建成功" << std::endl;
		}
		else
		{
			std::cout << "懒汉模式对象已经创建成功，无须再建" << std::endl;
		}

		return instrance;
    }

    static CSingletonPatternLazyMan* delInstrance()
    {
        delete instrance;
		instrance = NULL;

        return instrance;
    }

private:
    CSingletonPatternLazyMan(/* args */);
    ~CSingletonPatternLazyMan();

private:
    // 此处仅仅是声明 
    static CSingletonPatternLazyMan* instrance;
};

} // FjhApp


// 测试用例如下:
// #include <iostream>
// #include "singleton_pattern_lazy_man.h"

// using namespace std;
// using Singleton = FjhApp::CSingletonPatternLazyMan;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
//     Singleton* f1 = Singleton::getInstrance();
//     Singleton* f2 = Singleton::getInstrance();
//     Singleton* f3 = Singleton::getInstrance();
//     f1->sayHello();
//     f2->sayHello();
//     f3->sayHello();
//     return 0;
// }

// 输出如下:
// 设计模式测试用例
// 懒汉单例模式构造函数
// 懒汉模式对象创建成功
// 懒汉模式对象已经创建成功，无须再建
// 懒汉模式对象已经创建成功，无须再建
// Say Hello - 懒汉单例模式
// Say Hello - 懒汉单例模式
// Say Hello - 懒汉单例模式
