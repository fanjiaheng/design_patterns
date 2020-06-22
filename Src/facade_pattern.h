#pragma once

#include <iostream>

namespace FjhApp {
// 我们如今须要完毕两个工作：要完毕这两个工作。要完毕工作1我们须要依次完毕子工作
// Sub_Work1、Sub_Work3。要完毕工作2我们须要依次完毕工作Sub_Work2，Sub_Work3。
// Sub_Work4。为了能让用户与这些子工作分离。我们採用外观模式在中间插入一个工作处
// 理中心Work，这个Work负责处理用户的需求已经集成对应的底层子系统.

class CSubWork1 //子工作1
{
public:
    void working1()
    {
        std::cout << "Doing Sub Work1 ...." << std::endl;
    }
};

class CSubWork2 //子工作2
{
public:
    void working2()
    {
        std::cout << "Doing Sub Work2 ...." << std::endl;
    }
};

class CSubWork3 //子工作3
{
public:
    void working3()
    {
        std::cout << "Doing Sub Work3 ...." << std::endl;
    }
};

class CSubWork4 //子工作4
{
public:
    void working4()
    {
        std::cout << "Doing Sub Work4 ...." << std::endl;
    }
};

class CWorker //总工作，客户与之打交道
{
public:
    void work1() // 总工作1
    {
        w1.working1();
        w3.working3();
    }

    void work2() // 总工作2
    {
        w2.working2();
        w3.working3();
        w4.working4();
    }

private:
    CSubWork1 w1;
    CSubWork2 w2;
    CSubWork3 w3;
    CSubWork4 w4;
};

} //FjhApp

// 测试用例
// #include "Src/facade_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     FjhApp::CWorker *w = new FjhApp::CWorker();

//     std::cout << "开始调用总工作1" << std::endl;
//     w->work1();
//     std::cout << "开始调用总工作2" << std::endl;
//     w->work2();

//     return 0;
// }

// 输出
// 设计模式测试用例
// 开始调用总工作1
// Doing Sub Work1 ....
// Doing Sub Work3 ....
// 开始调用总工作2
// Doing Sub Work2 ....
// Doing Sub Work3 ....
// Doing Sub Work4 ....
