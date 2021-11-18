#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分查找
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        // 当left大于right时说明已找到ans，退出循环
        while (left <= right) {
            // 找到中间位置：左右指针/2 + 左指针（右位移）
            int mid = ((right - left) >> 1) + left;
            //如果目标值小于中间值，说明目标值在左侧，则把右指针一到mid左侧，搜索左侧空间
            // 注意这里：ans = mid要在小于等于这种情况里，因为可能没有target == nums[mid]这种情况！
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
                //如果目标值大于中间值，说明目标值在右侧，则把右指针一到mid右侧，搜索右侧空间
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};


int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(6);

    Solution sol;
    int res = sol.searchInsert(vec,2);
    cout<< res << endl;
}