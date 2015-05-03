/*=============================================================================
#     FileName: 71-SimplifyPath.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 22:33:37
#      Version: 0.0.1
#   LastChange: 2015-04-29 23:01:09
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    //12ms
    string simplifyPath(string path) { 
        int len = path.length(), start = 0, end;
        if (len == 0) {
            return "";
        } else if (len == 1) {
            return path == "/" ? "/" : "";
        }
        if (path[0] != '/') {
            return "";
        }
        stack<string> path_stack;
        while (start < len && path[start] == '/') {
            start ++;
        }
        while (start < len) {
            end = start;
            while (end < len - 1 && path[end + 1] != '/') {
                end ++;
            }
            string tmp = path.substr(start, end - start + 1);
            if (tmp == "..") {
                if (!path_stack.empty()) {
                    path_stack.pop();
                }
            } else if (tmp == ".") {
            } else {
                path_stack.push(tmp);
            }
            if (end == len - 1) {
                start = len;
            } else {
                start = end + 1;
                while (start < len && path[start] == '/') {
                    start ++;
                }
            }
        }
        if (path_stack.empty()) {
            return "/";
        }
        string ret;
        while (!path_stack.empty()) {
            string tmp = path_stack.top();
            path_stack.pop();
            ret = "/" + tmp + ret;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    printf("%s\n", solution.simplifyPath("/home/").c_str());
    printf("%s\n", solution.simplifyPath("/a/./b/../../c/").c_str());

    return 0;
}
