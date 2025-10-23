#pragma once

class Balance {
private:
    double amountOwe;
    double amountGetBack;

public:
    double getAmountOwe() const {
        return amountOwe;
    }

    void setAmountOwe(double amountOwe) {
        this->amountOwe = amountOwe;
    }

    double getAmountGetBack() const {
        return amountGetBack;
    }

    void setAmountGetBack(double amountGetBack) {
        this->amountGetBack = amountGetBack;
    }
};