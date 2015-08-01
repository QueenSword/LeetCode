/*=============================================================================
#     FileName: 232-ImplementQueueUsingStacks.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-29 19:29:05
#      History:
=============================================================================*/

#include <iostream>
#include <stack>

using namespace std;

class Queue {
    public:
        stack<int> stack1, stack2;
        // Push element x to the back of queue.
        void push(int x) {
            stack1.push(x);
        }
        // Removes the element from in front of queue.
        void pop(void) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack2.pop();
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        // Get the front element.
        int peek(void) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int front = stack2.top();
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
            return front;
        }
        // Return whether the queue is empty.
        bool empty(void) {
            return stack1.empty();
        }
};
