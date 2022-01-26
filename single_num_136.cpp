//
// Created by 王月艺 on 2022/1/26.
//
#include<unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;

        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]++;//每出现一次+1
        }

        for(auto i=hashmap.begin(); i!=hashmap.end(); ++i){
            if(i->second == 1){
                return i->first;
            }
        }
        return 0;

    }
};

int main(){
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);

    Solution sol;
    sol.singleNumber(nums);
}