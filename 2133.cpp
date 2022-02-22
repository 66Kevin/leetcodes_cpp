//
// Created by 王月艺 on 2022/2/22.
//
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> occur;   // 每一行/列出现过的整数
        // 判断每一行是否符合要求
        for (int i = 0; i < n; ++i) {
            occur.clear();   // 确保统计前哈希表为空
            for (int j = 0; j < n; ++j) {
                if (occur.count(matrix[i][j])) {
                    // 出现重复整数，该行不符合要求
                    return false;
                }
                occur.insert(matrix[i][j]);
            }
        }
        // 判断每一列是否符合要求
        for (int i = 0; i < n; ++i) {
            occur.clear();   // 确保统计前哈希表为空
            for (int j = 0; j < n; ++j) {
                if (occur.count(matrix[j][i])) {
                    // 出现重复整数，该列不符合要求
                    return false;
                }
                occur.insert(matrix[j][i]);
            }
        }
        return true;
    }
};
