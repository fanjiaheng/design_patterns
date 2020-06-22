#pragma once

#include <iostream>

// 工厂方法模式的特点：
// 工厂方法模式抽象出了工厂类，提供创建具体产品的接口，交由子类去实现。
// 工厂方法模式的应用并不只是为了封装具体产品对象的创建，而是要把具体产品对象的创建放到具体工厂类实现。

// 工厂方法模式的缺陷：
// 每新增一个产品，就需要增加一个对应的产品的具体工厂类。相比简单工厂模式而言，工厂方法模式需要更多的类定义。
// 一条生产线只能一个产品。
namespace FjhApp
{
   // 鞋子抽象类
    class Shoes
    {
    public:
        virtual ~Shoes() {}
        virtual void Show() = 0;
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

    // 阿迪达斯鞋子
    class AdidasShoes : public Shoes
    {
    public:
        void Show()
        {
            std::cout << "我是阿迪达斯球鞋，我的广告语:Impossible is nothing" << std::endl;
        }
    };

    // 李宁鞋子
    class LiNingShoes : public Shoes
    {
    public:
        void Show()
        {
            std::cout << "我是李宁球鞋，我的广告语：Everything is possible" << std::endl;
        }
    };

    // 总鞋厂
    class ShoesFactory
    {
    public:
        virtual Shoes *CreateShoes() = 0;
        virtual ~ShoesFactory() {}
    };

    // 耐克生产者/生产链
    class NiKeProducer : public ShoesFactory
    {
    public:
        Shoes *CreateShoes()
        {
            return new NiKeShoes();
        }
    };

    // 阿迪达斯生产者/生产链
    class AdidasProducer : public ShoesFactory
    {
    public:
        Shoes *CreateShoes()
        {
            return new AdidasShoes();
        }
    };

    // 李宁生产者/生产链
    class LiNingProducer : public ShoesFactory
    {
    public:
        Shoes *CreateShoes()
        {
            return new LiNingShoes();
        }
    };

} // namespace FjhApp

// 测试用例
// #include <iostream>
// #include "Src/factory_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     // ================ 生产耐克流程 ==================== //
//     // 鞋厂开设耐克生产线
//     FjhApp::ShoesFactory *niKeProducer = new FjhApp::NiKeProducer();
//     // 耐克生产线产出球鞋
//     FjhApp::Shoes *nikeShoes = niKeProducer->CreateShoes();
//     // 耐克球鞋广告喊起
//     nikeShoes->Show();
//     // 释放资源
//     delete nikeShoes;
//     delete niKeProducer;

//     // ================ 生产阿迪达斯流程 ==================== //
//     // 鞋厂开设阿迪达斯生产者
//     FjhApp::ShoesFactory *adidasProducer = new FjhApp::AdidasProducer();
//     // 阿迪达斯生产线产出球鞋
//     FjhApp::Shoes *adidasShoes = adidasProducer->CreateShoes();
//     // 阿迪达斯球鞋广喊起
//     adidasShoes->Show();
//     // 释放资源
//     delete adidasShoes;
//     delete adidasProducer;

//     return 0;
// }

// 输出：
// 设计模式测试用例
// 我是耐克球鞋，我的广告语：Just do it
// 我是阿迪达斯球鞋，我的广告语:Impossible is nothing