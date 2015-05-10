/*=============================================================================
#     FileName: 133-CloneGraph.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 22:13:00
#      Version: 0.0.1
#   LastChange: 2015-05-09 23:06:34
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    
    void dfs(UndirectedGraphNode *root, UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &node_map) {
        for (int i = 0; i < node->neighbors.size(); i ++) {
            root->neighbors.push_back(node_map[node->neighbors[i]->label]);
            if (root->neighbors[i]->neighbors.empty() && !(node->neighbors[i]->neighbors.empty()) &&  root->neighbors[i] != root) {
                dfs(root->neighbors[i], node->neighbors[i], node_map);
            }
        }
        return ;
    }
    
    //82ms
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        queue<UndirectedGraphNode *> node_queue;
        map<int, UndirectedGraphNode *> node_map;
        node_queue.push(node);
        while (!node_queue.empty()) {
            UndirectedGraphNode *temp = node_queue.front();
            node_queue.pop();
            if (node_map.find(temp->label) == node_map.end()) {
                UndirectedGraphNode *new_node = new UndirectedGraphNode(temp->label);
                node_map.insert(pair<int, UndirectedGraphNode*>(new_node->label, new_node));
                for (int i = 0; i < temp->neighbors.size(); i ++) {
                    if (temp != temp->neighbors[i]) {
                        node_queue.push(temp->neighbors[i]);
                    }
                }
            }
            
        }

        UndirectedGraphNode *root = node_map[node->label];
        dfs(root, node, node_map);
        return root;
        

    }
};
