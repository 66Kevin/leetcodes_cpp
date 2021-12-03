#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);

        // 同样不需要从0开始，因为dp[0] = 0
        for(int i = 1; i <= num; i++){
            if(i % 2 == 0){ // 偶数
                dp[i] = dp[i / 2];
            }
            else{ // 奇数
                dp[i] = dp[(i - 1) / 2] + 1;
            }
        }
        return dp;
    }
};