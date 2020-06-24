#pragma once

#include <iostream>

namespace FjhApp
{
    // ============================================
    // 枪械基类
    class Gun_base
    {
    public:
        virtual ~Gun_base() {}

        virtual void fire() const = 0;
    };

    // 手枪
    class Pistol : public Gun_base
    {
    public:
        void fire() const
        {
            std::cout << "手枪发射—— biu biu biu！" << std::endl;
        }
    };

    // 步枪
    class Rifle : public Gun_base
    {
    public:
        void fire() const
        {
            std::cout << "步枪发射—— tu tu tu！" << std::endl;
        }
    };

    // 狙击枪
    class Awp : public Gun_base
    {
    public:
        void fire() const
        {
            std::cout << "狙击枪发射—— peng！" << std::endl;
        }
    };
    // ============================================

    // ============================================
    // 战士基类
    class Fighter_base
    {
    public:
        virtual ~Fighter_base() {}

        virtual void fight(Gun_base *gun) const = 0;
    };

    // 战士A
    class Fighter_A : public Fighter_base
    {
    public:
        void fight(Gun_base *gun) const
        {
            std::cout << "我是战士A！ ———— ";
            gun->fire();
        }
    };

    // 战士B
    class Fighter_B : public Fighter_base
    {
    public:
        void fight(Gun_base *gun) const
        {
            std::cout << "我是战士B！ ———— ";
            gun->fire();
        }
    };

    // 战士C
    class Fighter_C : public Fighter_base
    {
    public:
        void fight(Gun_base *gun) const
        {
            std::cout << "我是战士C！ ———— ";
            gun->fire();
        }
    };
    // ============================================

} // namespace FjhApp

// 测试用例:
// #include <iostream>
// #include "src/bridge_pattern.h"

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

// 	// 创建三种枪
// 	FjhApp::Gun_base* gun_01 = new FjhApp::Pistol();
// 	FjhApp::Gun_base* gun_02 = new FjhApp::Rifle();
// 	FjhApp::Gun_base* gun_03 = new FjhApp::Awp();

// 	// 创建三种战士
// 	FjhApp::Fighter_base* A = new FjhApp::Fighter_A();
// 	FjhApp::Fighter_base* B = new FjhApp::Fighter_B();
// 	FjhApp::Fighter_base* C = new FjhApp::Fighter_C();

// 	// 不同战士搭配不同枪械展示
// 	C->fight(gun_02);

// 	delete gun_01;
// 	delete gun_02;
// 	delete gun_03;

// 	delete A;
// 	delete B;
// 	delete C;

//     return 0;
// }
// 输出:
// 设计模式测试用例
// 我是战士C！ ———— 步枪发射—— tu tu tu！