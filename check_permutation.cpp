//
// Created by 王月艺 on 2022/2/12.
//
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        unordered_map<char, int> dic;
        for (char c : s1) {
            dic[c] += 1;
        }
        for (char c : s2) {
            dic[c] -= 1;
        }
        for (auto kv : dic) {
            if (kv.second != 0)
                return false;
        }
        return true;
    }
};