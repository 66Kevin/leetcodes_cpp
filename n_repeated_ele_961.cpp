//
// Created by 王月艺 on 2022/2/9.
//
#include<unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> hashmap;

        for(int i=0; i<len; ++i){
            hashmap[nums[i]] +=1;
        }

        for(auto i = hashmap.begin(); i!=hashmap.end(); ++i){
            if(i -> second == (len/2)){
                return i->first;
            }
        }

        return 0;
    }
};