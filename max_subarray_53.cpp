#include <iostream>
#include <vector>
using namespace std;

// 暴力解法
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int numSize = nums.size();
        int max = INT32_MIN; // 定义成最小值，不断更新成最大值

        for (int i = 0; i < numSize; ++i)
        {
            int sum =0;
            for (int j = i; i < numSize; ++j) //从j=i开始遍历，可以包含任何一种情况
            {
                sum+=nums[j];
                if(sum > max)
                {
                    max = sum;
                }
            } 
        }

        return max;
    }
};

// 贪心法
// 从左到右迭代，一个个数字加过去，如何sum<0,重新找子序串
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int numSize = nums.size();
        int res = INT32_MIN; // 定义成最小值，不断更新成最大值

        int sum =0;
        for (int i = 0; i < numSize; i++)
        {
            sum += nums[i];
            res = max(sum, res);
            if(sum<0){
                sum=0; 
            }
            
        }

    }
};

//分治法
class Solution{
public:
  int maxSubArray(vector<int> &nums){
    return find(nums, 0, nums.size()-1);
  }
  
  int find(vector<int> &nums, int start, int end){
    //边界条件
    if(start == end) return nums[end];
    if(start > end) return -1;
    
    //declare
    int left_max = 0, right_max = 0, ml = 0, mr = 0;
    int middle = (start + end)/2;
    
    //find max in left or right
    left_max = find(nums, start, middle-1);
    right_max = find(nums, middle+1, end);
    //find max through middle using Greedy algorithm
    for (int i=middle-1, sum=0; i>=start; --i){
      sum += nums[i];
      if(ml<sum) ml=sum;
    }
    for (int i=middle+1, sum=0; i<=end; ++i){
      sum += nums[i];
      if(mr<sum) mr=sum;
    }
    return max(max(left_max, right_max),ml+nums[middle]+mr);
  }
};


int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    Solution sol;
    int res = sol.maxSubArray(nums);
    cout << res << endl;
}