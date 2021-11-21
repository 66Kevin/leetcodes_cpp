#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            // 1234 这种情况，直接在最后一位加一返回即可
            if (digits[i] != 0) return digits;
        }

        // 9999 这种情况下，个位加1后，所有的位变为0，并且重新申请新vector让最大位为1即可
        vector<int> res(digits.size() + 1);
        res[0] = 1;
        return res;
    }
};