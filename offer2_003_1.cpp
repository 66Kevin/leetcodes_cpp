class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);

        for(int i = 0; i <= n; ++i){
            if(i % 2 == 1){
                dp[i] = dp[i-1] + 1; // 奇数等于上一位数中1的个数+1
            }else{
                dp[i] = dp[i / 2];   // 偶数等于上一个偶数中1的个数
            }
        }
        return dp;
    }
};


