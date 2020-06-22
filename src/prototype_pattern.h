#pragma once

#include <iostream>
#include <string>

// 原型模式和建造者模式、工厂方法模式一样，都属于创建型模式的一种。简单的来说，我们使用原型模式，就是为了创建对象。
// 不过，适合原型模式的最好选择如下：

// 1.当我们的对象类型不是开始就能确定的，而这个类型是在运行期确定的话，那么我们通过这个类型的对象克隆出一个新的对象
// 比较容易一些；

// 2.有的时候，我们需要一个对象在某个状态下的副本，此时，我们使用原型模式是最好的选择；例如：一个对象，经过一段处理
// 之后，其内部的状态发生了变化；这个时候，我们需要一个这个状态的副本，如果直接new一个新的对象的话，但是它的状态是不
// 对的，此时，可以使用原型模式，将原来的对象拷贝一个出来，这个对象就和之前的对象是完全一致的了；

// 3.当我们处理一些比较简单的对象时，并且对象之间的区别很小，可能就几个属性不同而已，那么就可以使用原型模式来完成，省
// 去了创建对象时的麻烦了；

// 4.有的时候，创建对象时，构造函数的参数很多，而自己又不完全的知道每个参数的意义，就可以使用原型模式来创建一个新的对
// 象，不必去理会创建的过程。

// ->适当的时候考虑一下原型模式，能减少对应的工作量，减少程序的复杂度，提高效率
namespace FjhApp {

// Prototype抽象类定义了克隆自身的Clone接口，由派生类进行实现
class Prototype
{
public:
    Prototype(std::string s)
    {
        str = s;
    }
    Prototype()
    {
        str = "";
    }
    void show()
    {
        std::cout << str << std::endl;
    }
    virtual Prototype *clone() = 0;

private:
    std::string str;
};
 
class ConcretePrototype1 :public Prototype
{
public:
    ConcretePrototype1(std::string s) :Prototype(s){}
    ConcretePrototype1(){}
    virtual Prototype *clone()
    {
        ConcretePrototype1 *p = new ConcretePrototype1();
        *p = *this;
        return p;
    }
};
 
 
class ConcretePrototype2 :public Prototype
{
public:
    ConcretePrototype2(std::string s) :Prototype(s){}
    ConcretePrototype2(){}
    virtual Prototype *clone()
    {
        ConcretePrototype2 *p = new ConcretePrototype2();
        *p = *this;
        return p;
    }
};

} // FjhApp

// 测试用例
// #include "Src/prototype_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     FjhApp::ConcretePrototype1 *test = new FjhApp::ConcretePrototype1("小李");
//     FjhApp::ConcretePrototype2 *test2 = (FjhApp::ConcretePrototype2 *)test->clone();
//     test->show();
//     test2->show();

//     return 0;
// }

// 输出
// 设计模式测试用例
// 小李
// 小李
