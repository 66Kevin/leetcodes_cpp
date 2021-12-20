#include<unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> hashmap1;
        if(len==0){
            return false;
        }

        for(int i=0; i<len; ++i){
            if(!hashmap1.count(nums[i])){
                 hashmap1[nums[i]] = i;
            }else{
                 int res = abs(hashmap1[nums[i]] - i);
                 if(res <= k){
                     return true;
                 }
                 hashmap1[nums[i]] = i;
            }
        }
        return false;
    }
};