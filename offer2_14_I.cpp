class Solution {
public:
    int cuttingRope(int n) {
        vector<int> f(n + 1); // 1.状态定义 f[i]表示绳子长度为i时的最大乘积
        f[2] = 1; // 3. 初始化
        for (int i = 3; i < n + 1; i ++) {
            for (int j = 1; j <= i / 2; j ++) { 
                f[i] = max(f[i], max(j * (i - j), j * f[i - j])); // 2 状态转移方程
            }
        }
        return f[n];  // 4. 返回值
    }
};
