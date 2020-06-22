#pragma once

#include <iostream>

namespace FjhApp {
// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};

// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 优衣库衣服
class UniqloClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
    }
};

// 抽象模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类
template <class AbstractProduct_t>
class AbstractFactory
{
public:
    virtual AbstractProduct_t *CreateProduct() = 0;
    virtual ~AbstractFactory() {}
};

// 具体模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类，ConcreteProduct_t 产品具体类
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t>
{
public:
    AbstractProduct_t *CreateProduct()
    {
        return new ConcreteProduct_t();
    }
};

} //FjhApp

// 测试用例：
// #include <iostream>
// #include "Src/abstract_template_factory.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
    
//     // 构造耐克鞋的工厂对象
//     FjhApp::ConcreteFactory<FjhApp::Shoes, FjhApp::NiKeShoes> nikeFactory;
//     // 创建耐克鞋对象
//     FjhApp::Shoes *pNiKeShoes = nikeFactory.CreateProduct();
//     // 打印耐克鞋广告语
//     pNiKeShoes->Show();

//     // 构造优衣库衣服的工厂对象
//     FjhApp::ConcreteFactory<FjhApp::Clothe, FjhApp::UniqloClothe> uniqloFactory;
//     // 创建优衣库衣服对象
//     FjhApp::Clothe *pUniqloClothe = uniqloFactory.CreateProduct();
//     // 打印优衣库广告语
//     pUniqloClothe->Show();

//     // 释放资源
//     delete pNiKeShoes;
//     pNiKeShoes = NULL;

//     delete pUniqloClothe;
//     pUniqloClothe = NULL;

//     return 0;
// }

// 输出：
// 设计模式测试用例
// 我是耐克球鞋，我的广告语：Just do it
// 我是优衣库衣服，我的广告语：I am Uniqlo
