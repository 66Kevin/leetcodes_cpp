class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= target; ++j){
                int stone = stones[i-1];
                if(stone > j){ // 背包放不下体积为stones[i]的石头
                    dp[i][j] = dp[i-1][j];
                }else{ // 背包放的下体积为stones[i]的石头
                    dp[i][j] = max(stone + dp[i-1][j-stone], dp[i-1][j]);
                }
            }
        }
        return (sum - dp[n][target]) - dp[n][target];
    }
};
