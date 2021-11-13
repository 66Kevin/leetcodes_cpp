#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        // 如果不是偶数，直接返回false
        if (n % 2 == 1) {
            return false;
        }
        // 1.使用unordered_map提高速度
        // 2.*** key和value反着定义，可以直接使用是否相等来判断两符号是否为一组 ***
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution sol;
    bool res;
    res = sol.isValid("{}{}()[}");
    cout << res << endl;
}