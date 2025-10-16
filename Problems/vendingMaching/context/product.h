#pragma once
#include <string>
using namespace std;

enum class ProductType {
    CHOCOLATE,
    CHIPS,
    SOFT_DRINKS
};

struct Product {
    ProductType type;
    string name;
    double price;
    string code;
    int quantity;

    Product(ProductType t, string n, double p, string c, int q)
        : type(t), name(n), price(p), code(c), quantity(q) {}

    string toString() const {
        return "Product[name=" + name + ", code=" + code + ", price=" + to_string(price) + ", quantity=" + to_string(quantity) + "]";
    }
};