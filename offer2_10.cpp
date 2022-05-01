class Solution {
public:
    int fib(int n) {
        //递归超时，动态规划上场
       int mod = 1e9 + 7;
       if (n <= 1) return n;

        vector<int> dp(n+1); //dp[i]:斐波那契数列第 i 个数字
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++ i ) {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= mod;
        }
        
        return dp[n];
    }
};
