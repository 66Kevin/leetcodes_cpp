#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){return 0;}
        int slow = 0, fast = 1;
        while(fast < nums.size()){
            if(nums[fast] != nums[slow]){
                slow = slow + 1;
                nums[slow] = nums[fast];
            }
            fast = fast + 1;
        }
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