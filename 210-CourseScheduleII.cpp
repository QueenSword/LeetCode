/*=============================================================================
#     FileName: 210-CourseScheduleII.cpp
#         Desc: AC, 552ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 09:14:48
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
            queue<int> nodeQueue;
            vector<int> result, inDegree(numCourses, 0);
            int len = prerequisites.size();
            for (int i = 0; i < len; i ++) {
                pair<int, int> edge = prerequisites[i];
                inDegree[edge.first] ++;
            }
            for (int i = 0; i < numCourses; i ++) {
                if (inDegree[i] == 0) {
                    nodeQueue.push(i);
                }
            }
            while (!nodeQueue.empty()) {
                int node = nodeQueue.front();
                nodeQueue.pop();
                result.push_back(node);
                for (int i = 0; i < len; i ++) {
                    pair<int, int> edge = prerequisites[i];
                    if (edge.second == node) {
                        inDegree[edge.first] --;
                        if (inDegree[edge.first] == 0) {
                            nodeQueue.push(edge.first);
                        }
                    }
                }
            }
            if ((int)result.size() < numCourses) {
                vector<int> impossible;
                return impossible;
            }
            return result;
        }
};
