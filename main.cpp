#include <iostream>
#include "Src/proxy_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::Girl mm("小娟");
    FjhApp::Proxy pro(mm);
    pro.GiveChocolate();
    pro.GiveDolls();
    pro.GiveFlowers();

    return 0;
}