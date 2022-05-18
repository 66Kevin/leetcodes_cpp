class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 和前面合并好还是不和前面合并好
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            dp[i]=max(nums[i], dp[i-1]+nums[i]);
        return *max_element(begin(dp),end(dp));
    }
};
