#pragma once
#include "group.h"
#include "../User/user.h"
#include <vector>
#include <string>
using namespace std;

class GroupController {
private:
    vector<std::unique_ptr<Group>> groupList;
    ExpenseController* expenseController = nullptr;

public:
    GroupController() = default;

    void setExpenseController(ExpenseController* ec) {
        expenseController = ec;
    }

    void createGroup(string groupId, string groupName, User* createdByUser) {
        auto group = std::make_unique<Group>();
        group->setGroupId(groupId);
        group->setGroupName(groupName);
        group->addMember(*createdByUser);
        // wire expense controller if available
        if (expenseController) group->setExpenseController(expenseController);

        groupList.push_back(std::move(group));
    }

    Group* getGroup(const string& groupId) {
        for (auto& group : groupList) {
            if (group->getGroupId() == groupId) {
                return group.get();
            }
        }
        return nullptr; // Return nullptr if group not found
    }
};