#include<unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_2;

        for(auto ch: s){
            map_s[ch] +=1;
        }
        for(auto ch: t){
            map_2[ch] +=1;
        }
        char res=' ';
        for(auto iter=map_2.begin(); iter!= map_2.end(); ++iter){
            if(!map_s.count(iter->first)){
                res = iter ->first;
                break;
            }
            if(map_2[iter->first] - map_s[iter->first] == 1){
                res = iter->first;
                break;
            }

        }

        return res;
    }
};