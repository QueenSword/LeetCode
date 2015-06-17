/*=============================================================================
#     FileName: 134-GasStation.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 08:00:49
#      Version: 0.0.1
#   LastChange: 2015-06-17 20:28:06
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    //8ms
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(), total = 0, curMax = 0, curMin = 0, startMax = 0, MAX = INT_MIN, MIN = INT_MAX, startMAX = 0, endMIN = 0;
        for (int i = 0; i < len; i ++) {
            int diff = gas[i] - cost[i];
            total += diff;
            if (curMax <= 0) {
                curMax = diff;
                startMax = i;
            } else {
                curMax += diff;
            }
            if (curMin >= 0) {
                curMin = diff;
            } else {
                curMin += diff;
            }
            if (MAX < curMax) {
                MAX = curMax;
                startMAX = startMax;
            }
            if (MIN > curMin) {
                MIN = curMin;
                endMIN = i;
            }
        }
        return total < 0 ? -1 : MAX >= total - MIN ? startMAX : (endMIN + 1) % len;
    }
};
