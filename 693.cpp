//
// Created by 王月艺 on 2022/2/24.
//

class Solution {
public:

    bool hasAlternatingBits(int n) {
        n = (n ^ (n >> 1));
        return (n & ((long)n + 1)) == 0;
    }
};