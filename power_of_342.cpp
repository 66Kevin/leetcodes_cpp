//
// Created by 王月艺 on 2022/2/9.
//

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n&(n-1)) == 0 && n % 3 == 1;
    }
};