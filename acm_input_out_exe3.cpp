/*
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输入：
a,c,bb
f,dddd
nowcoder
输出：
a,bb,c
dddd,f
nowcoder
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main(){    
    string line;
    while (getline(cin, line)) { //读取一行
        istringstream sin(line); //#include<sstream>
        string str;
        vector<string> strs;
        while (getline(sin, str, ',')) {
            strs.push_back(str);
        }
        sort(strs.begin(),strs.end());
        int num = strs.size() - 1;
        for(int i = 0; i < num; ++i) {
            cout <<strs[i] <<',';
        }
        cout <<strs[num] <<'\n';
    }
    return 0;
}

