#include<unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap;

        int len = nums.size();
        for(int i=0; i<len; ++i){
            hashmap[nums[i]] += 1;
        }
        
        for(auto iter = hashmap.begin(); iter != hashmap.end(); ++iter){
            if(iter->second > 1){
                return true;
            }
        }

        return false;
        
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    Solution sol;
    int res = sol.containsDuplicate(nums);
    cout << res << endl;
}