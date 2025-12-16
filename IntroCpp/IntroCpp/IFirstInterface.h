#pragma once

#include <string>


class  IFirstInterface
{
public:
    // Virtual destructor must be created
    virtual ~IFirstInterface() = default;

    // functions must be virtual

    virtual void interact() = 0;
    
};
