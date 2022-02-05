//
// Created by 王月艺 on 2022/2/5.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {

        int result;
        long multi = 1;
        int len = columnTitle.length();
        for(int i=len-1; i>=0; --i){
            int num = columnTitle[i] - 'A' + 1;
            result+= num * multi;
            multi *=26;
        }

        return result;

    }
};