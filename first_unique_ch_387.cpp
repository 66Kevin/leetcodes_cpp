#include<unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> hashmap;

        for(auto ch : s){
            hashmap[ch] +=1;
        }

        for(int i = 0; i < s.size(); ++i){
            if(hashmap[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};