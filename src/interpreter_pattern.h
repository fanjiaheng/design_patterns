#pragma once

#include <iostream>
#include <string>

namespace FjhApp {

class Context {   // 包含解释器之外的全局信息
private:
    std::string input;
    std::string output;
public:
    void SetInput(std::string i) { input = i; }
    std::string GetInput() { return input; }
    void SetOutput(std::string o) { output = o; }
    std::string GetOutput() { return output; }
};

class AbstractExpression {
public:
    virtual void Interpret(Context* context) = 0;
    virtual ~AbstractExpression() {}
};

class TerminalExpression : public AbstractExpression {  // 终结符表达式
public:
    void Interpret(Context* context) {
        std::cout << "TerminalExpression: " << context->GetInput() << ", " << context->GetOutput() << std::endl;
    }
};

class NonterminalExpression : public AbstractExpression {   // 非终结符表达式
private:
    AbstractExpression* expression;
public:
    NonterminalExpression(AbstractExpression* e) { expression = e; }
    void Interpret(Context* context) {
        std::cout << "NonterminalExpression: " << context->GetInput() << ", " << context->GetOutput() << std::endl;
        expression->Interpret(context);
    }
};

}
// 测试用例:
// #include <iostream>
// #include "src/interpreter_pattern.h"

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     FjhApp::Context* c = new FjhApp::Context();
//     c->SetInput("Hello");
//     c->SetOutput("World");

//     FjhApp::AbstractExpression* exp1 = new FjhApp::TerminalExpression();
//     FjhApp::AbstractExpression* exp2 = new FjhApp::NonterminalExpression(exp1);
//     exp1->Interpret(c); // TerminalExpression: Hello, World
//     exp2->Interpret(c); // NonterminalExpression: Hello, World
//                         // TerminalExpression: Hello, World
//     delete exp1;
//     delete exp2;

//     return 0;
// }

// 输出:
// 设计模式测试用例
// TerminalExpression: Hello, World
// NonterminalExpression: Hello, World
// TerminalExpression: Hello, World