#pragma once
#include "jump.h"
using namespace std;

class Cell {
public:
    Jump* jump;

    Cell(): jump(nullptr) {};
};