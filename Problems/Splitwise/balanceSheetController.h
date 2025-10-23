#pragma once
#include "Expense/Split/split.h"
#include "User/user.h"
#include "userExpenseBalanceSheet.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BalanceSheetController {
public:
    void updateUserExpenseBalanceSheet(User* expensePaidBy, vector<Split*> splits, double totalExpenseAmout) {
        //update the total amount paid of the expense paid by user

        UserExpenseBalanceSheet* paidByUserBalanceSheet = expensePaidBy->getUserExpenseBalanceSheet();
        paidByUserBalanceSheet->setTotalPayment(paidByUserBalanceSheet->getTotalPayment() + totalExpenseAmout);
        
        for(auto& split : splits) {
            User* userOwe = split->getUser();
            UserExpenseBalanceSheet* oweUserExpenseSheet = userOwe->getUserExpenseBalanceSheet();
            double oweAmount = split->getAmountOwe();

            if(expensePaidBy->getUserId() == userOwe->getUserId()) {
                paidByUserBalanceSheet->setTotalYourExpense(paidByUserBalanceSheet->getTotalYourExpense() + oweAmount);
            }
            else {
                paidByUserBalanceSheet->setTotalYouGetBack(paidByUserBalanceSheet->getTotalYouGetBack() + oweAmount);
                Balance* userOweBalance;

                if(paidByUserBalanceSheet->getUserVsBalance().find(userOwe->getUserId()) != paidByUserBalanceSheet->getUserVsBalance().end()) {
                    userOweBalance = paidByUserBalanceSheet->getUserVsBalance().at(userOwe->getUserId());
                }
                else {
                    userOweBalance = new Balance();
                    paidByUserBalanceSheet->getUserVsBalance()[userOwe->getUserId()] = userOweBalance;
                }

                userOweBalance->setAmountGetBack(userOweBalance->getAmountGetBack() + oweAmount);

                //update the total amount owe of the user who owe
                oweUserExpenseSheet->setTotalYouOwe(oweUserExpenseSheet->getTotalYouOwe() + oweAmount);
                oweUserExpenseSheet->setTotalYourExpense(oweUserExpenseSheet->getTotalYourExpense() + oweAmount);

                Balance* userPaidBalance;

                if(oweUserExpenseSheet->getUserVsBalance().find(expensePaidBy->getUserId()) != oweUserExpenseSheet->getUserVsBalance().end()) {
                    userPaidBalance = oweUserExpenseSheet->getUserVsBalance().at(expensePaidBy->getUserId());
                }
                else {
                    userPaidBalance = new Balance();
                    oweUserExpenseSheet->getUserVsBalance()[expensePaidBy->getUserId()] = userPaidBalance;
                }

                userPaidBalance->setAmountOwe(userPaidBalance->getAmountOwe() + oweAmount);
            }
        }
    }

    void showBalanceSheetOfUser(User* user) {
        cout<<"--------------------------"<<endl;
        cout<<"Balance Sheet of User: "<<user->getUserId()<<endl;

        UserExpenseBalanceSheet* userExpenseBalanceSheet = user->getUserExpenseBalanceSheet();

        cout<<"Total Expense: "<<userExpenseBalanceSheet->getTotalYourExpense()<<endl;
        cout<<"Total Payment: "<<userExpenseBalanceSheet->getTotalPayment()<<endl;
        cout<<"Total You Owe: "<<userExpenseBalanceSheet->getTotalYouOwe()<<endl;
        cout<<"Total You Get Back: "<<userExpenseBalanceSheet->getTotalYouGetBack()<<endl;

        for(auto& entry : userExpenseBalanceSheet->getUserVsBalance()) {
            string otherUserId = entry.first;
            Balance* balance = entry.second;

            cout<<"Balance with User "<<otherUserId<<": Owe = "<<balance->getAmountOwe()<<", Get Back = "<<balance->getAmountGetBack()<<endl;
        }

        cout<<"--------------------------"<<endl;
    }
};