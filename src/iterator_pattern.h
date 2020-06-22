#pragma once

#include <string>
#include <vector>

namespace FjhApp {

class Iterator
{
public:
    Iterator(){};
    virtual ~Iterator(){};
    virtual std::string First() = 0;
    virtual std::string Next() = 0;
    virtual std::string GetCur() = 0;
    virtual bool IsEnd() = 0;
};

class Aggregate
{
public:
    virtual int Count() = 0;
    virtual void Push(const std::string& strValue)=0;
    virtual std::string Pop(const int nIndex)=0;
    virtual Iterator* CreateIterator() = 0;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* pAggregate):m_nCurrent(0),Iterator()
    {
        m_Aggregate = pAggregate;
    }
    std::string First()
    {
        return m_Aggregate->Pop(0);
    }
    std::string Next()
    {
        std::string strRet;
        m_nCurrent++;
        if(m_nCurrent < m_Aggregate->Count())
        {
            strRet = m_Aggregate->Pop(m_nCurrent);
        }
        return strRet;
    }
    std::string GetCur()
    {
        return m_Aggregate->Pop(m_nCurrent);
    }
    bool IsEnd()
    {
        return ((m_nCurrent >= m_Aggregate->Count()) ? true: false);
    }
private:
    Aggregate* m_Aggregate;
    int m_nCurrent;
};

class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate():m_pIterator(NULL)
    {
        m_vecItems.clear();
    }
    ~ConcreteAggregate()
    {
        if(NULL != m_pIterator)
        {
            delete m_pIterator;
            m_pIterator = NULL;
        }
    }
    Iterator* CreateIterator()
    {
        if(NULL == m_pIterator)
        {
            m_pIterator = new ConcreteIterator(this);
        }
        return m_pIterator;
    }
    int Count()
    {
        return m_vecItems.size();
    }
    void Push(const std::string& strValue)
    {
        m_vecItems.push_back(strValue);
    }
    std::string Pop(const int nIndex)
    {
        std::string strRet;
        if(nIndex < Count())
        {
            strRet = m_vecItems[nIndex];
        }
        return strRet;
    }
private:
    std::vector<std::string> m_vecItems;
    Iterator* m_pIterator;
};


} //FjhApp

// 测试用例：
// #include <iostream>
// #include "src/iterator_pattern.h"

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
    
//     FjhApp::ConcreteAggregate* pName = NULL;
//     pName = new FjhApp::ConcreteAggregate();
//     if(NULL != pName)
//     {
//         pName->Push("hello");
//         pName->Push("word");
//         pName->Push("cxue");
//     }

//     FjhApp::Iterator* iter = NULL;
//     iter = pName->CreateIterator();
//     if(NULL != iter)
//     {
//         std::string strItem = iter->First();
//         while(!iter->IsEnd())
//         {
//             std::cout << iter->GetCur() << " is ok" << std::endl;
//             iter->Next();
//         }
//     }

//     return 0;
// }

// 输出：
// 设计模式测试用例
// hello is ok
// word is ok
// cxue is ok
