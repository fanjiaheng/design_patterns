#include <iostream>
#include "Src/factory_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    // ================ 生产耐克流程 ==================== //
    // 鞋厂开设耐克生产线
    FjhApp::ShoesFactory *niKeProducer = new FjhApp::NiKeProducer();
    // 耐克生产线产出球鞋
    FjhApp::Shoes *nikeShoes = niKeProducer->CreateShoes();
    // 耐克球鞋广告喊起
    nikeShoes->Show();
    // 释放资源
    delete nikeShoes;
    delete niKeProducer;

    // ================ 生产阿迪达斯流程 ==================== //
    // 鞋厂开设阿迪达斯生产者
    FjhApp::ShoesFactory *adidasProducer = new FjhApp::AdidasProducer();
    // 阿迪达斯生产线产出球鞋
    FjhApp::Shoes *adidasShoes = adidasProducer->CreateShoes();
    // 阿迪达斯球鞋广喊起
    adidasShoes->Show();
    // 释放资源
    delete adidasShoes;
    delete adidasProducer;

    return 0;
}