#include "singleton_pattern_lazy_man.h"
#include <iostream>


namespace FjhApp {

CSingletonPatternLazyMan* CSingletonPatternLazyMan::instrance = NULL;

CSingletonPatternLazyMan::CSingletonPatternLazyMan()
{
    std::cout << "懒汉单例模式构造函数" << std::endl;
}

CSingletonPatternLazyMan::~CSingletonPatternLazyMan()
{
    std::cout << "懒汉单例模式析构函数" << std::endl;
}

void CSingletonPatternLazyMan::sayHello(void)
{
    std::cout << "Say Hello - 懒汉单例模式" << std::endl;
}

} // FjhApp