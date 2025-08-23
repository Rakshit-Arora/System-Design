#pragma once
#include <string>
using namespace std;

struct Pizza {
    virtual ~Pizza() = default;
    virtual string getDescription() const = 0;
    virtual double cost() const = 0; 
    virtual void prepare() const = 0;
};