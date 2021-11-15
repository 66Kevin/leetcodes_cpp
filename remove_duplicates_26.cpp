#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if(n==0){
            return 0;
        } 

        // 快慢指针
        int slow;
        for (int fast = 0; fast < nums.size(); fast++){
            if (nums[fast] != nums[slow]){
                nums[++slow] = nums[fast];
            }
        }
        //返回曼指针后一位
        return slow + 1;

    }
};

int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    Solution sol;
    int res = sol.removeDuplicates(nums);
    cout << res << endl;
}