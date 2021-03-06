#pragma once

#include <iostream>

// 状态模式，当一个对象的内在状态改变时允许改变其行为，这个对象看起来像是改变了类本身。
// 状态模式主要解决的是当控制一个对象状态转换的条件表达式过于复杂时的情况。把状态的判
// 断逻辑转移到到表示不同状态的一系列类当中，可以把复杂的判断逻辑简化。
namespace FjhApp {

class Context;

class State
{
public:
	virtual void Operation(Context *pContext) = 0;
};

class Context
{
private:
	State * m_state;
public:
	Context(State * p)
	{
		m_state = p;
	}
	~Context()
	{
		if (nullptr != m_state)
			delete m_state;
	}
	void SomeOperation()
	{
		m_state->Operation(this);
	}
	void setState(State * p)
	{
		delete m_state;
		m_state = p;
	}
};

class ConcreteStateA : public State
{
public:
	void Operation(Context * pContext);
};

class ConcreteStateB : public State
{
	void Operation(Context * pContext)
	{
		std::cout << "OperationB" << std::endl;
		// 这里有一个要更换状态，主要看实际需求
		pContext->setState(new ConcreteStateA());
	}
};

void ConcreteStateA::Operation(Context * pContext)
{
    std::cout << "OperationA" << std::endl;
    // 这里有一个要更换状态，主要看实际需求
    pContext->setState(new ConcreteStateB());
}

} //FjhApp

// 测试用例：
// #include <iostream>
// #include "Src/state_pattern.h"

// using namespace std;


// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
//     // 状态模式
// 	FjhApp::Context *p = new FjhApp::Context(new FjhApp::ConcreteStateA());
// 	p->SomeOperation();
// 	p->SomeOperation();
// 	delete p;

//     return 0;
// }

// 输出：
// 设计模式测试用例
// OperationA
// OperationB
