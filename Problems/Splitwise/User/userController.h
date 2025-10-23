#pragma once
#include "user.h"
#include <vector>
using namespace std;

class UserController {
private:
    vector<std::unique_ptr<User>> userList;

public:
    UserController() = default;

    // takes ownership
    void addUser(std::unique_ptr<User> user) {
        userList.push_back(std::move(user));
    }

    // convenience overload: create unique_ptr from raw pointer
    void addUser(User* user) {
        addUser(std::unique_ptr<User>(user));
    }

    User* getUserById(const string& userId) {
        for (auto& user : userList) {
            if (user->getUserId() == userId) {
                return user.get();
            }
        }
        return nullptr; // Return nullptr if user not found
    }

    vector<User*> getAllUsers() const {
        vector<User*> out;
        for (const auto& u : userList) out.push_back(u.get());
        return out;
    }
};