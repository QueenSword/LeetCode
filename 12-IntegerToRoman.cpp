/*=============================================================================
#     FileName: 12-IntegerToRoman.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 04:22:51
#      Version: 0.0.1
#   LastChange: 2015-04-05 04:22:51
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

    //70ms
    string intToRoman(int num) {

        vector<pair<int, string> > vec;
        vec.push_back(pair<int, string>(1000, "M"));
        vec.push_back(pair<int, string>(900, "CM"));
        vec.push_back(pair<int, string>(500, "D"));
        vec.push_back(pair<int, string>(400, "CD"));
        vec.push_back(pair<int, string>(100, "C"));
        vec.push_back(pair<int, string>(90, "XC"));
        vec.push_back(pair<int, string>(50, "L"));
        vec.push_back(pair<int, string>(40, "XL"));
        vec.push_back(pair<int, string>(10, "X"));
        vec.push_back(pair<int, string>(9, "IX"));
        vec.push_back(pair<int, string>(5, "V"));
        vec.push_back(pair<int, string>(4, "IV"));
        vec.push_back(pair<int, string>(1, "I"));
        string result = "";
        
        for (int i = 0; i < vec.size(); i ++) {
            while (num >= vec[i].first) {
                num -= vec[i].first;
                result += vec[i].second;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(20) << endl;

    return 0;
}
