#pragma once

#include <iostream>
#include <vector>

namespace FjhApp
{

class FlyWeight
{
public:
    FlyWeight(){};
    virtual ~FlyWeight(){};
    virtual void operation() = 0;
};

class ConcreteFlyWeight: public FlyWeight
{
public:
    ConcreteFlyWeight(){};
    ~ConcreteFlyWeight(){};
    
    void operation();
};

void ConcreteFlyWeight::operation()
{
    std::cout << "I'm ConcreteFlyWeight!" << std::endl;
}

class FlyWeightFactory
{
public:
    FlyWeightFactory();
    ~FlyWeightFactory();

    FlyWeight* GetFlyWeight(int key);

private:
    std::vector<FlyWeight*> m_flyWeights;//很多时候为了增加效率，使用hash表之类的结构，这里简单的使用vector
};

FlyWeightFactory::FlyWeightFactory()
{
    FlyWeight* tmp = new ConcreteFlyWeight();
    m_flyWeights.push_back(tmp);
}

FlyWeightFactory::~FlyWeightFactory()
{
    FlyWeight* tmp = m_flyWeights.at(0);
    delete tmp;
    tmp = NULL;
}

FlyWeight* FlyWeightFactory::GetFlyWeight(int key)
{
    //简单点表示
    return m_flyWeights.at(key);
}

} //FjhApp

// 测试用例
// #include <iostream>
// #include "Src/flyweight_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     FjhApp::FlyWeightFactory* factory = new FjhApp::FlyWeightFactory();
//     FjhApp::FlyWeight* flyWeight = factory->GetFlyWeight(0);
//     flyWeight->operation();

//     return 0;
// }

// 输出:
// 设计模式测试用例
// I'm ConcreteFlyWeight!
