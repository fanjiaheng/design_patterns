#pragma once

// 饿汉单例：在类装载时完成了初始化，静态成员对象初始化成功
// 优点：线程安全
// 缺点：不管你用不用这个对象，他都会先创建出来，会造成浪费内存空间
namespace FjhApp
{
    class CSingletonPatternHungryMan
    {
    public:
        static CSingletonPatternHungryMan *instance()
        {
            static CSingletonPatternHungryMan inst;
            return &inst;
        }

        void sayHello(void);

    private:
        CSingletonPatternHungryMan(/* args */);
        ~CSingletonPatternHungryMan();

    private:
        /* data */
    };

} // namespace FjhApp

// 测试用例如下:
// #include <iostream>
// #include "singleton_pattern_hungry_man.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     cout << "设计模式测试用例" << std::endl;
//     FjhApp::CSingletonPatternHungryMan::instance()->sayHello();
//     FjhApp::CSingletonPatternHungryMan::instance()->sayHello();
//     FjhApp::CSingletonPatternHungryMan::instance()->sayHello();

//     return 0;
// }

// 输出如下:
// 设计模式测试用例
// 饿汉单例模式模式构造函数
// Say Hello - 饿汉单例模式模式
// Say Hello - 饿汉单例模式模式
// Say Hello - 饿汉单例模式模式
// 饿汉单例模式模式析构函数

// 可以发现构造和析构只调用了一次
