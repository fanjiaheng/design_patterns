#include <iostream>
#include "src/iterator_pattern.h"

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
    FjhApp::ConcreteAggregate* pName = NULL;
    pName = new FjhApp::ConcreteAggregate();
    if(NULL != pName)
    {
        pName->Push("hello");
        pName->Push("word");
        pName->Push("cxue");
    }

    FjhApp::Iterator* iter = NULL;
    iter = pName->CreateIterator();
    if(NULL != iter)
    {
        std::string strItem = iter->First();
        while(!iter->IsEnd())
        {
            std::cout << iter->GetCur() << " is ok" << std::endl;
            iter->Next();
        }
    }

    return 0;
}