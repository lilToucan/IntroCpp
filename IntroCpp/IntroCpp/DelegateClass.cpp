#include "DelegateClass.h"

DelegateClass::DelegateClass()
{
}

void DelegateClass::FunctionToTrigger(const std::string& x)
{
    std::cout <<x<<"\n";
}

void DelegateClass::FunctionToTriggerVoidVersion()
{
    std::cout <<"void 1"<<"\n";
}

void DelegateClass::FunctionToTriggerVoidVersion2()
{
    std::cout <<"void 2"<<"\n";
}

void DelegateClass::FunctionToTest()
{
    OnEventTriggered = std::bind(&DelegateClass::FunctionToTrigger,this,std::placeholders::_1);
    OnEventTriggered("random");

    auto x = [this] { FunctionToTriggerVoidVersion(); };
    auto y = [this] { FunctionToTriggerVoidVersion2(); };
    OnEventTriggeredVoid = {x,y};
    for (auto i : OnEventTriggeredVoid)
    {
        i();
    }
    
    // OnEventTriggeredVoid std::bind(DelegateClass::FunctionToTriggerVoidVersion,this);

    //OnEventTriggered.assign(DelegateClass::FunctionToTrigger,"a");
}
