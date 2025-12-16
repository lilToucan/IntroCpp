#pragma once
#include "IFirstInterface.h"
#include "Weapon.h"

class ClassWithInterface : public IFirstInterface, public Weapon
{
    public:
    ~ClassWithInterface() override;
    void interact() override;
};
