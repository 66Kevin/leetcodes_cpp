class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            if (n & 1)  cnt++;
            n = n >> 1; // 往右移动一位，缩小一位
        }
        return cnt;
    }
};

