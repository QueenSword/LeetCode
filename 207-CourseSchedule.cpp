/*=============================================================================
#     FileName: 207-CourseSchedule.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-17 22:21:02
#      Version: 0.0.1
#   LastChange: 2015-06-18 09:34:01
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //TLE
    /*bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {*/
        //vector<vector<bool> > graph(numCourses, vector<bool>(numCourses, false));
        //vector<int> inDir(numCourses, 0), outDir(numCourses, 0);
        //stack<int> s;
        //for (int i = 0; i < prerequisites.size(); i ++) {
            //pair<int, int> pre = prerequisites[i];
            //graph[pre.first][pre.second] = true;
        //}
        //for (int i = 0; i < numCourses; i ++) {
            //for (int j = 0; j < numCourses; j ++) {
                //if (graph[i][j]) {
                    //inDir[j] ++;
                    //outDir[i] ++;
                //}
            //}
        //}
        //for (int i = 0; i < numCourses; i ++) {
            //if (!inDir[i]) {
                //s.push(i);
            //}
        //}
        //while (!s.empty()) {
            //int pos = s.top();
            //s.pop();
            //for (int j = 0; j < numCourses; j ++) {
                //if (graph[pos][j]) {
                    //graph[pos][j] = false;
                    //inDir[j] --;
                    //if (!inDir[j]) {
                        //s.push(j);
                    //}
                //}
            //}
        //}
        //for (int i = 0; i < numCourses; i ++) {
            //if (!inDir[i]) {
                //return false;
            //}
        //}
        //return true;
    /*}*/
    //263ms
    bool hasCircle(vector<vector<int> > &graph, vector<bool> &visit, vector<bool> &mark, int current) {
        if (visit[current]) {
            return true;
        }
        if (mark[current]) {
            return false;
        }
        visit[current] = true;

        for (int i = 0; i < graph[current].size(); i ++) {
            if (hasCircle(graph, visit, mark, graph[current][i])) {
                return true;
            }
        }

        mark[current] = true;
        visit[current] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int len = prerequisites.size();
        if (len == 0) {
            return true;
        }
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<bool> visit(numCourses, false), mark(numCourses, false);
        for (auto prere : prerequisites) {
            graph[prere.first].push_back(prere.second);
        }
        for (int i = 0; i < numCourses; i ++) {
            if (hasCircle(graph, visit, mark, i)) {
                return false;
            }
        }
        return true;
    }
};
