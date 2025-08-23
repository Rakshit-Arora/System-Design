#pragma once
#include "pizza.h"
#include <string>

enum class Size { Small, Medium, Large };

class PlainPizza : public Pizza {
    Size size;

public:
    explicit PlainPizza(Size s);
    string getDescription() const override;
    double cost() const override;
    void prepare() const override;
};