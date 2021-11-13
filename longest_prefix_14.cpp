#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        if(!strs.size()){
            return "";
        }

        int min_len = strs[0].size(); //保存所有字符串的最小长度
        for(int i = 1; i < strs.size(); ++i){
            min_len = min_len > strs[i].size() ? strs[i].size() : min_len;
        }

        for(int j = 0; j < min_len; ++j){
            for(int i = 0; i < strs.size()-1; ++i){
                if(strs[i][j] == strs[i+1][j])  continue;
                else return strs[0].substr(0, j);
            }
        }

        return strs[0].substr(0, min_len); //如果前面没有碰到返回语句，说明前min_len个字符均相等
    }
};

int main(){
    vector<string> test;
    test.push_back("leet");
    test.push_back("lee");
    test.push_back("leetcode");
    test.push_back("lea");

    Solution sol;
    sol.longestCommonPrefix(test);

}
