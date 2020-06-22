#include <iostream>
#include "Src/abstract_factory_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    // ================ 生产耐克流程 ==================== //
    // 鞋厂开设耐克生产线
    FjhApp::Factory *niKeProducer = new FjhApp::NiKeProducer();
    
	// 耐克生产线产出球鞋
    FjhApp::Shoes *nikeShoes = niKeProducer->CreateShoes();
	// 耐克生产线产出衣服
    FjhApp::Clothe *nikeClothe = niKeProducer->CreateClothe();
    
	// 耐克球鞋广告喊起
    nikeShoes->Show();
	// 耐克衣服广告喊起
    nikeClothe->Show();
	
    // 释放资源
    delete nikeShoes;
	delete nikeClothe;
    delete niKeProducer;
    return 0;
}