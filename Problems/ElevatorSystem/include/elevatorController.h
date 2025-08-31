#pragma once
#include "elevatorCar.h"
#include "direction.h"
#include "elevatorState.h"
#include <queue>
#include <vector>
#include <unordered_set>
#include <functional>
#include <mutex>
#include <iostream>
using namespace std;

class ElevatorController {
    public:
        ElevatorCar* elevator;
        priority_queue<int, vector<int>, greater<int>> upQueue; // Min-heap for UP direction
        priority_queue<int> downQueue; // Max-heap for DOWN direction
        vector<int> pending;
        unordered_set<int> requestSet;

        ElevatorController(ElevatorCar* e) : elevator(e) {}

    private:
        bool exists(int floor) const {
            return requestSet.find(floor) != requestSet.end();
        }

        void addToUp(int floor) {
            if (exists(floor)) return;
            upQueue.push(floor);
            requestSet.insert(floor);
        }

        void addToDown(int floor) {
            if (exists(floor)) return;
            downQueue.push(floor);
            requestSet.insert(floor);
        }

        
        void addToPending(int floor) {
            if (exists(floor)) return;
            pending.push_back(floor);
            requestSet.insert(floor);
        }

        // move a pending vector value into the correct PQs
        void mergePendingToPQs() {
            for (int f : pending) {
                if (f > elevator->currentFloor) addToUp(f);
                else if (f < elevator->currentFloor) addToDown(f);
                else {
                // same floor -> service immediately
                moveTo(f);
                }
            }
            pending.clear();
        }

        // remove floor from tracking (when serviced)
        void removeRequestTracking(int floor) {
            requestSet.erase(floor);
        }

    public:

        // Request with direction
        void submitRequest(int floor, Direction dir) {
            if (elevator->state == ElevatorState::MOVING) {
                addToPending(floor);
                return;
            }

            if(dir == Direction::UP) {
                addToUp(floor);
            } else {
                addToDown(floor);
            }
        }
        
        // Generic Requrest
        void submitRequest(int floor) {
            if(exists(floor)) return;

            if(elevator -> state == ElevatorState::MOVING) {
                addToPending(floor);
                return;
            }

            if (floor == elevator->currentFloor) {
            // already here -> open door
                openAndClose();
                return;
            }
            if (floor > elevator->currentFloor) addToUp(floor);
            else addToDown(floor);
        }

        void controlElevatorOnce() {
            while(!upQueue.empty() || !downQueue.empty()) {
                if(elevator -> direction == Direction::UP) {
                    // Serve UP requests that are >= current floor.
                    // If an up request is below current floor, move it to pending for later.
                    bool servedAny = false;

                    while(!upQueue.empty()) {
                        int next = upQueue.top();
                        if(next < elevator -> currentFloor) {
                            upQueue.pop();
                            addToPending(next);
                            continue;
                        }
                        upQueue.pop();
                        removeRequestTracking(next);
                        moveTo(next);
                        servedAny = true;
                    }
                    mergePendingToPQs();

                    if(upQueue.empty() && !downQueue.empty()) {
                        elevator -> direction = Direction::DOWN;
                    } else if(upQueue.empty() && downQueue.empty() && pending.empty()) {
                        elevator -> state = ElevatorState::IDLE;
                        break;
                    } 
                }
                else {
                    bool servedAny = false;
                    while(!downQueue.empty()) {
                        int next = downQueue.top();
                        if(next > elevator -> currentFloor) {
                            downQueue.pop();
                            addToPending(next);
                            continue;
                        }
                        downQueue.pop();
                        removeRequestTracking(next);
                        moveTo(next);
                        servedAny = true;
                    }
                    mergePendingToPQs();
                    if(downQueue.empty() && !upQueue.empty()) {
                        elevator -> direction = Direction::UP;
                    } else if(downQueue.empty() && upQueue.empty() && pending.empty()) {
                        elevator -> state = ElevatorState::IDLE;
                        break;
                    }
                }
            }
        }

        // A helper to move elevator (instantaneous in this simulation)
        void moveTo(int floor) {
            if (elevator->currentFloor == floor) {
                openAndClose();
                return;
            }

            // set direction based on movement
            elevator->direction = (floor > elevator->currentFloor) ? Direction::UP : Direction::DOWN;
            elevator->state = ElevatorState::MOVING;

            std::cout << "[Elevator " << elevator->id << "] Moving from " << elevator->currentFloor << " to " << floor << "\n";
            elevator->currentFloor = floor;
            elevator->setDisplay();
            elevator->showDisplay();
            openAndClose();
        }

        void openAndClose() {
            elevator->door.openDoor();
            // simulate passengers entering/exiting
            elevator->door.closeDoor();
        }
};