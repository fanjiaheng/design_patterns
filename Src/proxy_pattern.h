#pragma once

#include <iostream>
#include <string>

namespace FjhApp {

// 大话设计模式里面的例子：小王想追求小娟，但他不认识小娟。但他的朋友小林认识小娟，所以
// 他通过让小林帮忙送礼物的方式追求小娟。这里的小林就是我们的代理！

// 女孩类
class Girl{
public:
    Girl(std::string name = ""):mName(name){}
    std::string getName()
    {
        return mName;
    }
private:
    std::string mName;
};

// 送礼物的接口
class GiveGift
{
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

// 送礼物类（小王）
class Puisuit : public GiveGift
{
public:
    Puisuit(Girl mm):mGirl(mm){}

    virtual void GiveDolls()
    {
        std::cout<<"送"<<mGirl.getName()<<"玩具！"<<std::endl;
    }

    virtual void GiveFlowers()
    {
        std::cout<<"送"<<mGirl.getName()<<"鲜花！"<<std::endl;
    }

    virtual void GiveChocolate()
    {
        std::cout<<"送"<<mGirl.getName()<<"巧克力！"<<std::endl;
    }
private:
    Girl mGirl;
};

// 送礼物代理类（小林）
class Proxy : public GiveGift
{
public:
    Proxy(Girl mm)
    {
        mPuisuit = new Puisuit(mm);
    }

    virtual void GiveDolls()
    {
        mPuisuit->GiveDolls();
    }

    virtual void GiveFlowers()
    {
        mPuisuit->GiveFlowers();
    }

    virtual void GiveChocolate()
    {
        mPuisuit->GiveChocolate();
    }
private:
    Puisuit* mPuisuit;

};


} //FjhAppFjhApp