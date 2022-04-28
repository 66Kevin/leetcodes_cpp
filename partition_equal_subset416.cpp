class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 题目是把整个数组分成两个子数组，因此每个数组的和为sum/2
        // dp[i][j]含义是从[0,i]选取若干数，是否存在一种方案使得被选取正整数和为j
       int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][nums[0]] = true; // nums第一个值
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num]; // 两个条件满足任意一个即可，所以是或操作
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};
