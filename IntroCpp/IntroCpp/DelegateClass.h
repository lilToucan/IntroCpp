#pragma once

#include <functional>
#include <vector>
#include <string>
#include <iostream>


class DelegateClass
{
    
public:
    DelegateClass();
    ~DelegateClass() = default;
    
    std::function<void(const std::string&)> OnEventTriggered;
    std::vector<std::function<void()>> OnEventTriggeredVoid;
    std::vector<int> a;

    void FunctionToTrigger(const std::string& x);
    void FunctionToTriggerVoidVersion();
    void FunctionToTriggerVoidVersion2();
    void FunctionToTest();
};
