//
// Created by 王月艺 on 2022/2/3.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0, "");
        return result;
    }
    void backtracking(int n, int left, int right, string str){
        if(right > left){
            return;
        }
        if(right == left && right == n && left == n){ //不能连续等于: right==left==n
            result.push_back(str);
            return;
        }
        if(left > right){
            backtracking(n, left, right+1, str+")");
        }
        if(left < n){
            backtracking(n, left+1, right, str+"(");
        }
    }
};

int main(){
    Solution sol;
    sol.generateParenthesis(2);
}