#include <iostream>
#include "Src/observer_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
    FjhApp::CSubject *dwq = new FjhApp::CSecretary(); // 创建观察者

    // 被观察的对象
    FjhApp::CObserver *xs = new FjhApp::CNBAObserver("xiaoshuai", dwq);
    FjhApp::CObserver *zy = new FjhApp::CNBAObserver("zouyue", dwq);
    FjhApp::CObserver *lm = new FjhApp::CStockObserver("limin", dwq);

    // 加入观察队列
    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);
    
    dwq->action = "去吃饭了"; // 事件
    dwq->notify(); // 通知

    dwq->action = "梁所长来了"; // 事件
    dwq->notify(); // 通知

    return 0;
}