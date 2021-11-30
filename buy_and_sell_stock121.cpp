#include <iostream>
#include <vector>
using namespace std;

// 动态规划，两个for循环暴力解法会超时
// 简化成一个for：《同时》记录最小值与最大收益
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 100000;
        int max_profit = 0;

        for(int price: prices){
            min_price = min(price, min_price);
            max_profit = max(price-min_price, max_profit);
        }

        return max_profit;
    }
};