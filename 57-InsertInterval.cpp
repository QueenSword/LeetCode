/*=============================================================================
#     FileName: 57-InsertInterval.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-11 11:24:06
#      Version: 0.0.1
#   LastChange: 2015-04-11 17:46:19
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
    //38ms
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        intervals.push_back(newInterval);
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
    return 0;

}
