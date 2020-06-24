#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

namespace FjhApp
{
    class Task
    {
    public:
        virtual void operation() = 0;
    };

    //单例
    class TaskRunner
    {
    public:
        static void add(Task &t)
        {
            tasks.push_back(&t);
        }
        static void run()
        {
            std::vector<Task *>::iterator it = tasks.begin();
            while (it != tasks.end())
            {
                (*it++)->operation();
            }
        }

    private:
        static std::vector<Task *> tasks;
        TaskRunner() {}
        static TaskRunner tr;
    };

    TaskRunner TaskRunner::tr;
    std::vector<Task *> TaskRunner::tasks;

    //创建随机延迟时间
    //clock() 返回从开启程序进程到调用clock()时的时间。
    class EventSimulator
    {
    public:
        EventSimulator() : creation(clock())
        {
            delay = CLOCKS_PER_SEC / 4 * (rand() % 20 + 1);
            std::cout << "delay = " << delay << std::endl;
        }

        bool fired()
        {
            return clock() > creation + delay;
        }

    private:
        clock_t creation;
        clock_t delay;
    };

    class Button
    {
    public:
        Button(std::string name) : pressed(false), id(name) {}
        void press() { pressed = true; }
        bool isPressed()
        {
            if (e.fired())
                press();
            return pressed;
        }

        friend std::ostream &operator<<(std::ostream &os, const Button &b)
        {
            return os << b.id;
        }

    private:
        bool pressed;
        std::string id;
        EventSimulator e;
    };

    class CheckButton : public Task
    {
    public:
        CheckButton(Button &b) : button(b), handled(false) {}
        void operation()
        {
            if (button.isPressed() && !handled)
            {
                std::cout << button << " pressed" << std::endl;
                handled = true;
            }
        }

    private:
        Button &button;
        bool handled;
    };

    void procedure1()
    {
        TaskRunner::run(); // check all events
    }
    void procedure2()
    {
        TaskRunner::run(); // check all events
    }
    void procedure3()
    {
        TaskRunner::run(); // check all events
    }

} // namespace FjhApp

// 测试用例:
// #include <iostream>
// #include "src/command_pattern.h"

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     srand(time(0));
//     FjhApp::Button b1("Button 1"),b2("Button 2"),b3("Button 3");
//     FjhApp::CheckButton cb1(b1),cb2(b2),cb3(b3);
//     FjhApp::TaskRunner::add(cb1);
//     FjhApp::TaskRunner::add(cb2);
//     FjhApp::TaskRunner::add(cb3);
//     std::cout<< "Control-C to exit" << std::endl;

//     while (true) {
//         FjhApp::procedure1();
//         FjhApp::procedure2();
//         FjhApp::procedure3();
//     }
//     return 0;
// }

// 输出:
// 设计模式测试用例
// delay = 3000000
// delay = 4500000
// delay = 3750000
// Control-C to exit
// Button 1 pressed
// Button 3 pressed
// Button 2 pressed
