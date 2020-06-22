#include "singleton_pattern_hungry_man.h"
#include <iostream>


namespace FjhApp {
CSingletonPatternHungryMan::CSingletonPatternHungryMan()
{
    std::cout << "饿汉单例模式模式构造函数" << std::endl;
}

CSingletonPatternHungryMan::~CSingletonPatternHungryMan()
{
    std::cout << "饿汉单例模式模式析构函数" << std::endl;
}

void CSingletonPatternHungryMan::sayHello(void)
{
    std::cout << "Say Hello - 饿汉单例模式模式" << std::endl;
}

} // FjhApp