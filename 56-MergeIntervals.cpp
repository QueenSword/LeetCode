/*=============================================================================
#     FileName: 56-MergeIntervals.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-11 11:24:06
#      Version: 0.0.1
#   LastChange: 2015-04-11 11:24:06
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval interval1, Interval interval2) {
    if (interval1.start < interval2.start) {
        return true;
    }
    if (interval1.start > interval2.start) {
        return false;
    }
    return interval1.end < interval2.end;
}

class Solution {
public:
    //28ms
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        Interval tmp(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > tmp.end) {
                result.push_back(tmp);
                tmp.start = intervals[i].start;
                tmp.end = intervals[i].end;
            } else {
                tmp.end = max(intervals[i].end, tmp.end);
            }
        }
        result.push_back(tmp);
        return result;
        
    }
};

int main() {
    Interval in1(1, 3);    
    Interval in2(2, 6);
    Interval in3(8, 10);
    Interval in4(15, 18);    
    vector<Interval> intervals;
    intervals.push_back(in1);
    intervals.push_back(in3);
    intervals.push_back(in4);
    intervals.push_back(in2);
    Solution solution;
    vector<Interval> result = solution.merge(intervals);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i].start << " " << result[i].end << endl;
    }
    cout << endl;
    return 0;

}
