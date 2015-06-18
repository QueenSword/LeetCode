/*=============================================================================
#     FileName: 225-ImplementStackUsingQueues.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 16:41:40
#      Version: 0.0.1
#   LastChange: 2015-06-18 16:41:40
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    queue<int> q[2];
    // Push element x onto stack.
    void push(int x) {
        if (q[0].empty() && q[1].empty()) {
        
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        
    }

    // Get the top element.
    int top() {
        
    }

    // Return whether the stack is empty.
    bool empty() {
        
    }
};
