#pragma once

#include <iostream>

namespace FjhApp
{
    // 适配器模式有两种：1.类的适配器 2.对象适配器，对象适配器更多一些。
    // 1.类适配器
    class ThreePhaseOutlet //三相插头
    {
    public:
        void doThreePhasePlugin()
        {
            std::cout << "三相插头强势插入！" << std::endl;
        }
    };

    class TwoPhaseOutlet //两相插头
    {
    public:
        virtual void doPlugin() = 0;
    };

    // 转接头，将三相插头转换为“两相插头”
    class OutletConvertor : public TwoPhaseOutlet, public ThreePhaseOutlet
    {
    public:
        void doPlugin()
        {
            doConvertor();
            doThreePhasePlugin();
        }

        void doConvertor()
        {
            std::cout << "三相插头转为两相插头！" << std::endl;
        }
    };

    // 2.对象适配器 --- 对象适配器是将需要适配的对象进行包装然后提供适配后的接口。
    class OutletConvertor1 : public TwoPhaseOutlet
    {
    public:
        OutletConvertor1(ThreePhaseOutlet out)
        {
            m_out = out;
        }
        void doPlugin()
        {
            doConvertor();
            m_out.doThreePhasePlugin();
        }
        void doConvertor()
        {
            std::cout << "三相插头转为两相插头！" << std::endl;
        }
        ThreePhaseOutlet m_out;
    };
    // 我们在构造的时候将具体需要适配的适配对象传入，这样便可以根据传入不同的对象，从而对该对象进行适配。
    // 而类适配器却无法选择对象，他是对整个类进行适配。也就是把所有的三相插口全部转换为两相的，而不是针对某一个。

} // namespace FjhApp