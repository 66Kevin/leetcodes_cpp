//
// Created by 王月艺 on 2022/2/12.
//
#include <string>
using namespace std;

class Solution {
public:
    bool checkString(std::string s) {
        int last_a = -1;
        int first_b = s.size();

        for(int i=0; i<s.size(); ++i){
            if(s[i] == 'a'){
                last_a = max(i, last_a);
            }
            if(s[i] == 'b'){
                first_b = min(i, first_b);
            }
        }

        return last_a < first_b;
    }
};