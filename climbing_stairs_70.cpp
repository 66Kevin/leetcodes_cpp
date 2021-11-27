#include <iostream>
using namespace std;

//爬楼梯是每次爬一层或爬两层，那么总的方法次数就是看前面一阶的方法次数(对应一次爬一层就到) 加上 往前数两阶的方法次数(对应一次爬两层就到)就OK。
class Solution {
public:
    int climbStairs(int n) {
    	n = n + 1; //赋值后的n 表示需要到达 第几阶才可以 
    	if(n == 1) return 1;
    	
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3;i<=n;i++)
        {
        	dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};