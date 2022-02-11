//
// Created by 王月艺 on 2022/2/11.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target){
                left +=1;
            }
            else if(sum > target){
                right -=1;
            }
            else{
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                return res;
            }
        }
        return res;
    }
};