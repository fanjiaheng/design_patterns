#pragma once

#include <iostream>

// 抽象工厂模式的特点：
// 提供一个接口，可以创建多个产品族中的产品对象。如创建耐克工厂，则可以创建耐克鞋子产品、衣服产品、裤子产品等。

// 抽象工厂模式的缺陷：
// 同工厂方法模式一样，新增产品时，都需要增加一个对应的产品的具体工厂类。
namespace FjhApp
{
    // 基类 衣服
    class Clothe
    {
    public:
        virtual void Show() = 0;
        virtual ~Clothe() {}
    };

    // 耐克衣服
    class NiKeClothe : public Clothe
    {
    public:
        void Show()
        {
            std::cout << "我是耐克衣服，时尚我最在行！" << std::endl;
        }
    };

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
            std::cout << "我是耐克球鞋，让你酷起来！" << std::endl;
        }
    };

    // 总厂
    class Factory
    {
    public:
        virtual Shoes *CreateShoes() = 0;
        virtual Clothe *CreateClothe() = 0;
        virtual ~Factory() {}
    };

    // 耐克生产者/生产链
    class NiKeProducer : public Factory
    {
    public:
        Shoes *CreateShoes()
        {
            return new NiKeShoes();
        }
        
        Clothe *CreateClothe()
        {
            return new NiKeClothe();
        }
    };

} // namespace FjhApp

// 测试用例：
// #include <iostream>
// #include "Src/abstract_factory_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
//     // ================ 生产耐克流程 ==================== //
//     // 鞋厂开设耐克生产线
//     FjhApp::Factory *niKeProducer = new FjhApp::NiKeProducer();
    
// 	// 耐克生产线产出球鞋
//     FjhApp::Shoes *nikeShoes = niKeProducer->CreateShoes();
// 	// 耐克生产线产出衣服
//     FjhApp::Clothe *nikeClothe = niKeProducer->CreateClothe();
    
// 	// 耐克球鞋广告喊起
//     nikeShoes->Show();
// 	// 耐克衣服广告喊起
//     nikeClothe->Show();
	
//     // 释放资源
//     delete nikeShoes;
// 	delete nikeClothe;
//     delete niKeProducer;
//     return 0;
// }

// 输出：
// 设计模式测试用例
// 我是耐克球鞋，让你酷起来！
// 我是耐克衣服，时尚我最在行！