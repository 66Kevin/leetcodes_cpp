//
// Created by 王月艺 on 2022/3/8.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const long long MOD = 1e9 + 7;
        long long ret = 0, n = staple.size(), m = drinks.size();
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        for (int i = 0; i < n; i++) {
            int left_pointer = 0, right_pointer = m - 1;
            while (left_pointer <= right_pointer) {
                int middle_pointer = (left_pointer + right_pointer) / 2;
                if (staple[i] + drinks[middle_pointer] <= x) left_pointer = middle_pointer + 1;
                else right_pointer = middle_pointer - 1;
            }
            ret += right_pointer + 1;
            ret %= MOD;
        }
        return ret;
    }
};
