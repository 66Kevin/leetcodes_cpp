//
// Created by 王月艺 on 2022/2/4.
//
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len<=1) return len;

        int maxLen = 0;
        int left=0; int right=0;
        unordered_set<char> occ;
        while(right < len){
            char currChar = s[right];
            if(!occ.count(currChar)){
                maxLen = max(maxLen, right-left+1);
                occ.insert(currChar);
                right++;
            }else{
                occ.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};