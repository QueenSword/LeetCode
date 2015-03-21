/*=============================================================================
#     FileName: 1-TwoSum.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-03-21 11:42:06
#      Version: 0.0.1
#   LastChange: 2015-03-21 11:52:11
#      History:
#               0.0.1 | qsword | init
=============================================================================*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    //25ms
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        int len = numbers.size();
        map<int, int> m;
        for (int i = 0; i < len; i ++) {
            if (m.size() == 0) {
                m.insert(pair<int, int >(numbers[i], i + 1));
            } else {
                map<int, int>::iterator it = m.find(target - numbers[i]);
                if (it == m.end()) {
                    m.insert(pair<int, int >(numbers[i], i + 1));
                } else {
                    result.push_back(it->second);
                    result.push_back(i + 1);
                    break;
                }
            }
            
        }
        return result;
    }

};

int main() {
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);
    Solution solution;

    vector<int> result = solution.twoSum(numbers, 9);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
