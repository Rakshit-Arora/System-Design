#pragma once
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Context {
private:
    map<string, int> mp;

public:
    void setVariable(string name, int val) {
        mp[name] = val;
    }

    int getVariable(string name) {
        if(mp.find(name) == mp.end()) return 0;

        return mp[name];
    }

    void Print() {
        for(auto it: mp) {
            cout << it.first << ":" << it.second << " ";
        }cout << endl;
    }
};