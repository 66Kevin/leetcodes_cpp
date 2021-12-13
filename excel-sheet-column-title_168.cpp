#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;

        while (columnNumber) {
            --columnNumber;
            res += columnNumber % 26 + 'A';
            columnNumber = columnNumber / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    sol.convertToTitle(701);

}