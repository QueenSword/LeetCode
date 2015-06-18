/*=============================================================================
#     FileName: 225-ImplementStackUsingQueues.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 16:41:40
#      Version: 0.0.1
#   LastChange: 2015-06-18 18:34:59
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    //0ms
    queue<int> q[2];

    // Push element x onto stack.
    void push(int x) {
        q[1].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(!q[1].empty()) {
            int x = q[1].front();
            q[1].pop();
            if (q[1].empty()) {
                q[0].swap(q[1]);
                return ;
            } else {
                q[0].push(x);
            }
        }
    }

    // Get the top element.
    int top() {
        while (!q[1].empty()) {
            int x = q[1].front();
            q[1].pop();
            q[0].push(x);
            if (q[1].empty()) {
                q[0].swap(q[1]);
                return x;
            }
        }
        return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[1].empty();
    }
};
