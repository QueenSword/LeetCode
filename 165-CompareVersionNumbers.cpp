/*=============================================================================
#     FileName: 165-CompareVersionNumbers.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 13:10:09
#      Version: 0.0.1
#   LastChange: 2015-05-12 13:15:06
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
	int string2Int(string str) {
		if (str == "0") {
			return 0;
		}
		while (str[0] == '0') {
			str = str.substr(1, str.size() - 1);
		}
		int result = 0;
		for (int i = 0; i < str.size(); i ++) {
			result *= 10;
			result += (int)(str[i] - '0');
		}
		return result;
	}

	int compareType(string str1, string str2) { //-1 <		0 = 	1 >
		int num1 = string2Int(str1), num2 = string2Int(str2);
		if (num1 < num2) {
			return -1;
		}
		if (num1 == num2) {
			return 0;
		}
		return 1;
	}

	void split(const string& src, const string& separator, vector<string>& dest) {
	    string str = src;
    	string substring;
	    string::size_type start = 0, index;
		do {
	        index = str.find_first_of(separator,start);
    	    if (index != string::npos) {    
	            substring = str.substr(start,index-start);
    	        dest.push_back(substring);
        	    start = str.find_first_not_of(separator,index);
            	if (start == string::npos) return;
        	}
    	} while (index != string::npos);
    
        substring = str.substr(start);
    	dest.push_back(substring);
	}

    //3ms
	int compareVersion(string version1, string version2) {
		vector<string> vec1, vec2;
		split(version1, ".", vec1);
		split(version2, ".", vec2);
		for (int i = 0; i < min(vec1.size(), vec2.size()); i ++) {
			int res = compareType(vec1[i], vec2[i]);
			if (res != 0) {
				return res;
			}
		}
		int len1 = vec1.size(), len2 = vec2.size();
		if (len1 == len2) {
			return 0;
		}
		if (len1 > len2) {
		    for (int i = len2; i < len1; i ++) {
		        if (string2Int(vec1[i]) != 0) {
		            return 1;
		        }
		    }
		    return 0;
		}
		for (int i = len1; i < len2; i ++) {
		    if (string2Int(vec2[i]) != 0) {
		        return -1;
		    }
		}
		return 0;
		
	}

};

