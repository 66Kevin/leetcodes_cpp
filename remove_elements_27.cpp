#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针，当fast！=val时，fast后移，fast值赋给slow，slow后移
        int slowIndex = 0; 
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {  
            if (val != nums[fastIndex]) { 
                nums[slowIndex++] = nums[fastIndex]; 
            }
        }
        return slowIndex;
    }
};