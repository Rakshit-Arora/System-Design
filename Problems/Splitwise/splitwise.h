#pragma once
#include "Expense/expenseSplitType.h"
#include "Expense/Split/split.h"
#include "Group/group.h"
#include "Group/groupController.h"
#include "User/user.h"
#include "User/userController.h"
#include "balanceSheetController.h"
#include <vector>
using namespace std;

class Splitwise {
private:
    std::unique_ptr<UserController> userController;
    std::unique_ptr<GroupController> groupController;
    std::unique_ptr<BalanceSheetController> balanceSheetController;
    std::unique_ptr<ExpenseController> expenseController;

public:
    Splitwise() {
        // create controllers and wire dependencies
    balanceSheetController = std::make_unique<BalanceSheetController>();
    userController = std::make_unique<UserController>();
    groupController = std::make_unique<GroupController>();
    expenseController = std::make_unique<ExpenseController>(balanceSheetController.get());
    // wire expense controller into group controller
    groupController->setExpenseController(expenseController.get());
    }

public:
    void demo() {
        setupUserAndGroup();

        //step:1 Add members to group
        Group* group = groupController->getGroup("G1001");
        if (!group) {
            cerr << "Group G1001 not found" << endl;
            return;
        }

        User* u2 = userController->getUserById("U1002");
        User* u3 = userController->getUserById("U1003");
        if (!u2 || !u3) {
            cerr << "One or more users not found when adding to group" << endl;
            return;
        }

        group->addMember(*u2);
        group->addMember(*u3);

        //step:2 Create Expense in group
            //1st expense
        vector<Split*> splits;
        Split* split1 = new Split(userController->getUserById("U1001"), 300);
        Split* split2 = new Split(userController->getUserById("U1002"), 300);
        Split* split3 = new Split(userController->getUserById("U1003"), 300);

        splits.push_back(split1);
        splits.push_back(split2);
        splits.push_back(split3);   

        group -> createExpense("E1001", "Dinner Expense", 900, userController->getUserById("U1001"), ExpenseSplitType::EQUAL, splits);

            //2nd expense
    vector<Split*> splits2;
    Split* split4 = new Split(userController->getUserById("U1001"), 400);
    Split* split5 = new Split(userController->getUserById("U1002"), 100);

    // push into splits2 (was incorrectly pushing into 'splits')
    splits2.push_back(split4);
    splits2.push_back(split5);

    group->createExpense("E1002", "Museum Tickets", 500, userController->getUserById("U1002"), ExpenseSplitType::UNEQUAL, splits2);

        //step:3 Show Balance Sheet of users
        for(auto& user : userController->getAllUsers()) {
            balanceSheetController->showBalanceSheetOfUser(user);
        }
    }

    void setupUserAndGroup() {
        //onboard users to splitwise app
        addUsersToSplitwiseApp();

        User* user1 = userController->getUserById("U1001");
        groupController->createGroup("G1001", "Trip to Goa", user1);
    }

    void addUsersToSplitwiseApp() {
        //Adding user1
        User* user1 = new User("U1001", "User1");

        //Adding user2
        User* user2 = new User("U1002", "User2");

        //Adding user3  
        User* user3 = new User("U1003", "User3");

        userController->addUser(user1);
        userController->addUser(user2);
        userController->addUser(user3);
    }
};