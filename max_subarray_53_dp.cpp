class Solution{
public:
  int maxSubArray(vector<int> &nums){
    // 动态规划：每一步找到最大的子序列：和前面合并好还是不和前面合并好
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = nums[0];

    for(int i=1; i<nums.size(); ++i){
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        result = max(dp[i], result);
    }

    return result;

  }
};
