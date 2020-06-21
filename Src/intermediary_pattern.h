#pragma once

#include <iostream>

namespace FjhApp
{

#define SAFE_DELETE(p) \
    if (p)             \
    {                  \
        delete p;      \
        p = NULL;      \
    }

    class Mediator;

    // 抽象同事类，每一个同事类都知道它的中介者对象；每一个同时对象在需要与其他的同事通信的时候
    // 而是与它的中介者通信。
    class Colleague
    {
    public:
        Colleague(Mediator *pMediator) : m_pMediator(pMediator) {}

        virtual void Send(wchar_t *message) = 0;

    protected:
        Mediator *m_pMediator;
    };

    class ConcreteColleague1 : public Colleague
    {
    public:
        ConcreteColleague1(Mediator *pMediator) : Colleague(pMediator) {}

        void Send(wchar_t *message);

        void Notify(wchar_t *message)
        {
            std::cout << "ConcreteColleague1 is handling the message." << std::endl;
            std::cout << message << std::endl;
        }
    };

    class ConcreteColleague2 : public Colleague
    {
    public:
        ConcreteColleague2(Mediator *pMediator) : Colleague(pMediator) {}

        void Send(wchar_t *message);

        void Notify(wchar_t *message)
        {
            std::cout << "ConcreteColleague2 is handling the message." << std::endl;
            std::cout << message << std::endl;
        }
    };

    // 抽象中介者类，它定义了一个接口用于与各个Colleague对象通信；
    class Mediator
    {
    public:
        virtual void Sent(wchar_t *message, Colleague *pColleague) = 0;
    };

    // 具体的中介者类，它通过协调各Colleague对象实现协作行为；并了解和维护它的各个Colleague；
    class ConcreteMediator : public Mediator
    {
    public:
        // The mediator forward the message
        void Sent(wchar_t *message, Colleague *pColleague)
        {
            ConcreteColleague1 *pConcreteColleague1 = dynamic_cast<ConcreteColleague1 *>(pColleague);
            if (pConcreteColleague1)
            {
                std::cout << "The message is from ConcreteColleague1. Now mediator forward it to ConcreteColleague2 " << std::endl;
                    if (m_pColleague2)
                {
                    m_pColleague2->Notify(message);
                }
            }
            else
            {
                if (m_pColleague1)
                {
                    m_pColleague1->Notify(message);
                }
            }
        }

        void SetColleague1(Colleague *pColleague)
        {
            m_pColleague1 = dynamic_cast<ConcreteColleague1 *>(pColleague);
        }

        void SetColleague2(Colleague *pColleague)
        {
            m_pColleague2 = dynamic_cast<ConcreteColleague2 *>(pColleague);
        }

    private:
        // The Mediator knows all the Colleague
        ConcreteColleague1 *m_pColleague1;
        ConcreteColleague2 *m_pColleague2;
    };

    void ConcreteColleague1::Send(wchar_t *message)
    {
        // The second parameter mark where the message comes from
        m_pMediator->Sent(message, this);
    }

    void ConcreteColleague2::Send(wchar_t *message)
    {
        m_pMediator->Sent(message, this);
    }

} // namespace FjhApp

// 测试用例如下:
#include "Src/intermediary_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    // Create the mediator
    FjhApp::Mediator *pMediator = new FjhApp::ConcreteMediator();

    FjhApp::Colleague *pColleague1 = new FjhApp::ConcreteColleague1(pMediator);
    FjhApp::Colleague *pColleague2 = new FjhApp::ConcreteColleague2(pMediator);

    FjhApp::ConcreteMediator *pConcreteMediator = dynamic_cast<FjhApp::ConcreteMediator *>(pMediator);
    pConcreteMediator->SetColleague1(pColleague1);
    pConcreteMediator->SetColleague2(pColleague2);

    wchar_t message[260] = L"Where are you from?";
    pColleague1->Send(message);

    return 0;
}

// 输出
// 设计模式测试用例
// The message is from ConcreteColleague1. Now mediator forward it to ConcreteColleague2 
// ConcreteColleague2 is handling the message.
// 0x7ffc305a4950
