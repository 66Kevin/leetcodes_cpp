#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        //先让两个字符串等长
        while (lenA < lenB)
        {
            a = '0' + a;
            ++lenA;
        }
        while (lenA > lenB)
        {
            b = '0' + b;
            ++lenB;
        }
        //满2进1
        for (int i = lenA - 1; i > 0; --i)
        {
            a[i] = a[i] - '0' + b[i];
            if (a[i] >= '2')
            {
                a[i] = (a[i] - '0') % 2 + '0';
                a[i - 1] = a[i - 1] + 1;
            }
        }
        //判断首位
        a[0] = a[0] - '0' + b[0];
        if (a[0] >= '2')
        {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};