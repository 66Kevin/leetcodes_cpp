//
// Created by 王月艺 on 2022/2/7.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i=0; i<32; ++i){
            int tmp = n&1;
            if(tmp){
                res +=1;
            }
            n >>=1;
        }
        return res;
    }
};