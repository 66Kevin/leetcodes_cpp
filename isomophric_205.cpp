#include<unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 只能用char组成map
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char x = s[i], y = t[i];
            // 当i对应的字符已经存在映射并且对应的value不等于，则无法构成同构
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
