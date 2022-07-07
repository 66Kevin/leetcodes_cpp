#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int main() {
    string str;
    vector<string> strs;
    while(cin >> str) {
        strs.push_back(str);
        if(cin.get() == '\n') {
            sort(strs.begin(), strs.end());
            int num = strs.size() - 1;
            for(int i = 0; i < num; ++i) {
                cout <<strs[i] <<' ';
            }
            cout <<strs[num] <<'\n';
            strs.clear();
        }
    }
    return 0;
}

