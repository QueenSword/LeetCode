/*=============================================================================
#     FileName: 138-CopyListWithRandomPointer.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 08:28:24
#      Version: 0.0.1
#   LastChange: 2015-05-10 08:41:47
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    //136ms
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return head;
        }

        map<RandomListNode *, RandomListNode *> node_map;
        RandomListNode *tail = head;
        while (tail) {
            RandomListNode *node = new RandomListNode(tail->label);
            node->next = tail->next;
            node->random = tail->random;
            node_map.insert(pair<RandomListNode *, RandomListNode *>(tail, node));
            tail = tail->next;
        }
        RandomListNode *new_head = node_map[head];
        tail = new_head;
        while (tail) {
            tail->next = node_map[tail->next];
            tail->random = node_map[tail->random];
            tail = tail->next;
        }
        return new_head;

    }
};
