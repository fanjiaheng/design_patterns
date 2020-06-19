#include <iostream>
#include "Src/singleton_pattern_hungry_man.h"
#include "Src/singleton_pattern_lazy_man.h"

using namespace std;
using Singleton = FjhApp::CSingletonPatternLazyMan;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    Singleton* f1 = Singleton::getInstrance();
    Singleton* f2 = Singleton::getInstrance();
    Singleton* f3 = Singleton::getInstrance();
    f1->sayHello();
    f2->sayHello();
    f3->sayHello();
    
    return 0;
}
