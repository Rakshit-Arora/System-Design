#pragma once
#include "pizzaDecorator.h"

class Pepperoni : public PizzaDecorator {
public:
    using PizzaDecorator::PizzaDecorator; // Inherit constructor
    string getDescription() const override;
    double cost() const override;
    void prepare() const override;
};