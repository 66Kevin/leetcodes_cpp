//
// Created by 王月艺 on 2022/1/29.
//
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) { // 相当于nums[right]!=0
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

