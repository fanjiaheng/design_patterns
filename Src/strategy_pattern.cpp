#include "strategy_pattern.h"
#include <iostream>

namespace FjhApp {

Strategy::Strategy()
{}

Strategy::~Strategy()
{}

ConcreteStrategyA::ConcreteStrategyA()
{}

ConcreteStrategyA::~ConcreteStrategyA()
{}

void ConcreteStrategyA::AlgrithmInterface()
{
    std::cout << "ConcreteStrategyA::AlgrithmInterface" << std::endl;
}

ConcreteStrategyB::ConcreteStrategyB()
{}

ConcreteStrategyB::~ConcreteStrategyB()
{}

void ConcreteStrategyB::AlgrithmInterface()
{
    std::cout << "ConcreteStrategyB::AlgrithmInterface" << std::endl;
}

Context::Context(Strategy* strategy)
{
    this->_strategy = strategy;
}

Context::~Context()
{
    delete this->_strategy;
}

void Context::DoAction()
{
    this->_strategy->AlgrithmInterface();
}

} //FjhApp