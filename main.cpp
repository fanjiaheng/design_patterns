#include <iostream>
#include "Src/abstract_template_factory.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
    // 构造耐克鞋的工厂对象
    FjhApp::ConcreteFactory<FjhApp::Shoes, FjhApp::NiKeShoes> nikeFactory;
    // 创建耐克鞋对象
    FjhApp::Shoes *pNiKeShoes = nikeFactory.CreateProduct();
    // 打印耐克鞋广告语
    pNiKeShoes->Show();

    // 构造优衣库衣服的工厂对象
    FjhApp::ConcreteFactory<FjhApp::Clothe, FjhApp::UniqloClothe> uniqloFactory;
    // 创建优衣库衣服对象
    FjhApp::Clothe *pUniqloClothe = uniqloFactory.CreateProduct();
    // 打印优衣库广告语
    pUniqloClothe->Show();

    // 释放资源
    delete pNiKeShoes;
    pNiKeShoes = NULL;

    delete pUniqloClothe;
    pUniqloClothe = NULL;

    return 0;
}