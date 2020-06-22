#pragma once

#include <iostream>

namespace FjhApp {

// 公司
class Company
{
public:
    virtual ~Company() {}
 
    // 校园招聘
    void Recruit()
    {
        std::cout << "---------- Begin ----------" << std::endl;
        CareerTalk();
        ReceiveResume();
        Interview();
        Offer();
        std::cout << "---------- End ----------" << std::endl;
    }
 
    // 宣讲会
    void CareerTalk() {
        std::cout << "Delivery" << std::endl;
    }
 
    // 接收简历
    void ReceiveResume() {
        std::cout << "Receive Resume" << std::endl;
    }
 
    // 面试
    virtual void Interview() = 0;
 
    // 发放 Offer
    virtual void Offer() = 0;
};

// 阿里
class Alibaba : public Company//派生类Alibaba继承自基类Company
{
public:
   // virtual void Interview() override {
    void Interview()
    {
        std::cout << "First interview -> Second interview -> Third interview" << std::endl;
    }
    //override表示子类覆盖掉父类的方法，调用时会调用子类的方法，父类对应的方法已经用virtual修饰。
    //如果派生类在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，否则代码将无法通过编译
    virtual void Offer() override
    {
        std::cout << "30W" << std::endl;
    }
};

// 腾讯
class Tencent : public Company//派生类Tencent也继承自基类Company
{
public:
    virtual void Interview() override
    {
        std::cout << "First interview -> Second interview" << std::endl;
    }
 
    virtual void Offer() override
    {
        std::cout << "25W" << std::endl;
    }
};

} //FjhApp

// 测试用例：
// #include <iostream>
// #include "Src/template_pattern.h"

// using namespace std;


// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
    
//     // 类的指针，用的是内存堆，是个永久变量，除非你释放它，需要用new运算符分配内存

//     // 阿里校招
//     FjhApp::Company *alibaba = new FjhApp::Alibaba();
//     alibaba->Recruit();
 
//     // 腾讯校招
//     FjhApp::Company *tencent = new FjhApp::Tencent();
//     tencent->Recruit();
 
//     delete tencent;
//     delete alibaba;

//     return 0;
// }

// 输出：
// 设计模式测试用例
// ---------- Begin ----------
// Delivery
// Receive Resume
// First interview -> Second interview -> Third interview
// 30W
// ---------- End ----------
// ---------- Begin ----------
// Delivery
// Receive Resume
// First interview -> Second interview
// 25W
// ---------- End ----------