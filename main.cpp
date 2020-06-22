#include <iostream>
#include "Src/flyweight_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::FlyWeightFactory* factory = new FjhApp::FlyWeightFactory();
    FjhApp::FlyWeight* flyWeight = factory->GetFlyWeight(0);
    flyWeight->operation();

    return 0;
}