#include <iostream>
#include "Src/simple_factory_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
    // 构造工厂对象
    FjhApp::ShoesFactory shoesFactory;

    // 从鞋工厂对象创建阿迪达斯鞋对象
    FjhApp::Shoes *pNikeShoes = shoesFactory.CreateShoes(FjhApp::NIKE);
    if (pNikeShoes != NULL)
    {
        // 耐克球鞋广告喊起
        pNikeShoes->Show();

        // 释放资源
        delete pNikeShoes;
        pNikeShoes = NULL;
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    FjhApp::Shoes *pLiNingShoes = shoesFactory.CreateShoes(FjhApp::LINING);
    if (pLiNingShoes != NULL)
    {
        // 李宁球鞋广告喊起
        pLiNingShoes->Show();

        // 释放资源
        delete pLiNingShoes;
        pLiNingShoes = NULL;
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    FjhApp::Shoes *pAdidasShoes = shoesFactory.CreateShoes(FjhApp::ADIDAS);
    if (pAdidasShoes != NULL)
    {
        // 阿迪达斯球鞋广告喊起
        pAdidasShoes->Show();

        // 释放资源
        delete pAdidasShoes;
        pAdidasShoes = NULL;
    }

    return 0;
}