//
// Created by 王月艺 on 2022/2/10.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
