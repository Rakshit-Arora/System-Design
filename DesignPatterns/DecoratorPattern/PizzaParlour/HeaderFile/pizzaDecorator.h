#pragma once
#include "pizza.h"
#include <memory>
using namespace std;

class PizzaDecorator : public Pizza {
protected:
    unique_ptr<Pizza> pizza; // Use smart pointer for automatic memory management
public:
    explicit PizzaDecorator(unique_ptr<Pizza> p) : pizza(std::move(p)) {}
    virtual ~PizzaDecorator() = default;
};