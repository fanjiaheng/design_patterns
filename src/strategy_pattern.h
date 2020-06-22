#pragma once 

namespace FjhApp {
class Strategy
{
public:
    ~Strategy();
    virtual void AlgrithmInterface()=0;
protected:
    Strategy();
private:
};

class ConcreteStrategyA : public Strategy
{
public:
    ConcreteStrategyA();
    ~ConcreteStrategyA();
    virtual void AlgrithmInterface();
protected:
private:
};

class ConcreteStrategyB : public Strategy
{
public:
    ConcreteStrategyB();
    ~ConcreteStrategyB();
    virtual void AlgrithmInterface();
protected:
private:
};

/*这个类是Strategy模式的关键，
  也是Strategy模式和Template模式的根本区别所在。
  *Strategy通过“组合”（委托）方式实现算法（实现）的异构，
  而Template模式则采取的是继承的方式
  这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
*/
class Context
{
public:
    Context(Strategy*);
    ~Context();
    void DoAction();
private:
    Strategy* _strategy;
};

} //FjhApp

// 测试用例：
// #include <iostream>
// #include "src/strategy_pattern.h"

// using namespace std;


// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
//     /*
//     Strategy模式和Template模式实际是实现一个抽象接口的两种方式：继承和组合之间的区别。
//     要实现一个抽象接口，继承是一种方式：我们将抽象接口声明在基类中，将具体的实现放在具体子类中。
//     组合（委托）是另外一种方式：我们将接口的实现放在被组合对象中，将抽象接口放在组合类中。
//     这两种方式各有优缺点
//     */
//     //策略A与B可替换
//     FjhApp::Strategy* pStr = new FjhApp::ConcreteStrategyA();
//     FjhApp::Context* pcon = new FjhApp::Context(pStr);
//     pcon->DoAction();

//     pStr = new FjhApp::ConcreteStrategyB();
//     pcon = new FjhApp::Context(pStr);
//     pcon->DoAction();

//     return 0;
// }

// 输出：
// 设计模式测试用例
// ConcreteStrategyA::AlgrithmInterface
// ConcreteStrategyB::AlgrithmInterface