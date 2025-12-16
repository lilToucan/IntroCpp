#pragma once
#include "IDrawable.h"

class Square : public IDrawable
{
public:
    void Draw() override;
};

class Circle: public IDrawable
{
    public:
    void Draw() override;
};
