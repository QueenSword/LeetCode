/*=============================================================================
#     FileName: 146-LRUCache.cpp
#         Desc: AC, 108ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 09:10:38
#      History:
=============================================================================*/

#include <leetcode.h>

struct ListNode1 {
    int key;
    int value;
    ListNode1 *prev;
    ListNode1 *next;
    ListNode1(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache{
    public:
        int capacity;
        ListNode1 *head, *tail;
        map<int, ListNode1 *> nodeMap;
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = NULL;
            tail = NULL;
        }
        int get(int key) {
            if (nodeMap.find(key) != nodeMap.end()) {
                ListNode1 *node = nodeMap[key];
                if (node == head) {
                } else if (node == tail) {
                    ListNode1 *prev = tail->prev;
                    prev->next = NULL;
                    tail->prev = NULL;
                    tail->next = head;
                    head->prev = tail;
                    head = tail;
                    tail = prev;
                } else {
                    ListNode1 *prev = node->prev, *next = node->next;
                    prev->next = next;
                    next->prev = prev;
                    node->prev = NULL;
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
                return node->value;
            }
            return -1;
        }
        void set(int key, int value) {
            if (nodeMap.find(key) != nodeMap.end()) {
                ListNode1 *node = nodeMap[key];
                node->value = value;
                if (node == head) {
                } else if (node == tail) {
                    ListNode1 *prev = tail->prev;
                    prev->next = NULL;
                    tail->prev = NULL;
                    tail->next = head;
                    head->prev = tail;
                    head = tail;
                    tail = prev;
                } else {
                    ListNode1 *prev = node->prev, *next = node->next;
                    prev->next = next;
                    next->prev = prev;
                    node->prev = NULL;
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
            } else {
                if ((int)nodeMap.size() < capacity) {
                    ListNode1 *node = new ListNode1(key, value);
                    if (!head) {
                        head = node;
                        tail = node;
                    } else {
                        head->prev = node;
                        node->next = head;
                        head = node;
                    }
                    nodeMap.insert(pair<int, ListNode1*>(key, head));
                } else {
                    ListNode1 *node = new ListNode1(key, value);
                    node->next = head;
                    head->prev = node;
                    head = node;
                    nodeMap.erase(nodeMap.find(tail->key));
                    tail = tail->prev;
                    tail->next = NULL;
                    nodeMap.insert(pair<int, ListNode1*>(key, node));
                }
            }
        }
};

