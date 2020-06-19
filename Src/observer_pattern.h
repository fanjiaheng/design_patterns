#pragma once

#include <list>
#include <string>
#include <iostream>


// Subject（目标）
// ——目标知道它的观察者。可以有任意多个观察者观察同一个目标；
// ——提供注册和删除观察者对象的接口。

// Observer（观察者）
// ——为那些在目标发生改变时需获得通知的对象定义一个更新接口。

// ConcreteSubject（具体目标）
// ——将有关状态存入各ConcreteObserver对象；
// ——当它的状态发生改变时，向它的各个观察者发出通知。

// ConcreteObserver（具体观察者）
// ——维护一个指向ConcreteSubject对象的引用；
// ——存储有关状态，这些状态应与目标的状态保持一致；
// ——实现Observer的更新接口以使自身状态与目标的状态保持一致。

// 观察者模式按照以下方式进行协作：

// 当ConcreteSubject发生任何可能导致其观察者与其本身状态不一致的改变时，它将通知它的各个观察者；
// 在得到一个具体目标的改变通知后，ConcreteObserver对象可向目标对象查询信息。ConcreteObserver使用
// 这些信息以使它的状态与目标对象的状态一致。

namespace FjhApp {

class CSubject;

//抽象观察者
class CObserver
{
public:
    CObserver(std::string name, CSubject *sub)
    {
        this->name = name;
        this->sub = sub;
    }

    virtual void update() = 0;

protected:
    std::string name;
    CSubject *sub;
};


//抽象通知者
class CSubject
{
public:
    virtual void attach(CObserver*) = 0;
    virtual void detach(CObserver*) = 0;
    virtual void notify() = 0;

public:
    std::string action;

protected:
    std::list<CObserver*> observers;
};


//具体的观察者，看股票的
class CStockObserver :public CObserver
{
public:
    CStockObserver(std::string name, CSubject *sub) :CObserver(name, sub){}
    void update();
};


//具体的观察者，看NBA的
class CNBAObserver :public CObserver
{
public:
    CNBAObserver(std::string name, CSubject *sub) :CObserver(name, sub){}
    void update();
};


//具体通知者，秘书
class CSecretary :public CSubject
{
    void attach(CObserver *observer)
    {
        observers.push_back(observer);
    }

    void detach(CObserver *observer)
    {
        std::list<CObserver *>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            if ((*iter) == observer)
            {
                observers.erase(iter);
            }
            ++iter;
        }
    }

    void notify()
    {
        std::list<CObserver *>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};

void CStockObserver::update()
{
    std::cout << name << " 收到消息：" << sub->action << std::endl;
    if (sub->action == "梁所长来了!")
    {
        std::cout << "我马上关闭股票，装做很认真工作的样子！" << std::endl;
    }
}
 
void CNBAObserver::update()
{
    std::cout << name << " 收到消息：" << sub->action << std::endl;
    if (sub->action == "梁所长来了!")
    {
        std::cout << "我马上关闭NBA，装做很认真工作的样子！" << std::endl;
    }
}

} // FjhApp

// 测试用例如下:
// #include <iostream>
// #include "Src/observer_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
    
//     FjhApp::CSubject *dwq = new FjhApp::CSecretary(); // 创建观察者

//     // 被观察的对象
//     FjhApp::CObserver *xs = new FjhApp::CNBAObserver("xiaoshuai", dwq);
//     FjhApp::CObserver *zy = new FjhApp::CNBAObserver("zouyue", dwq);
//     FjhApp::CObserver *lm = new FjhApp::CStockObserver("limin", dwq);

//     // 加入观察队列
//     dwq->attach(xs);
//     dwq->attach(zy);
//     dwq->attach(lm);
    
//     dwq->action = "去吃饭了"; // 事件
//     dwq->notify(); // 通知

//     dwq->action = "梁所长来了"; // 事件
//     dwq->notify(); // 通知

//     return 0;
// }

// 输出
// 设计模式测试用例
// xiaoshuai 收到消息：去吃饭了
// zouyue 收到消息：去吃饭了
// limin 收到消息：去吃饭了

// xiaoshuai 收到消息：梁所长来了!
// 我马上关闭NBA，装做很认真工作的样子！
// zouyue 收到消息：梁所长来了!
// 我马上关闭NBA，装做很认真工作的样子！
// limin 收到消息：梁所长来了!
// 我马上关闭股票，装做很认真工作的样子！
