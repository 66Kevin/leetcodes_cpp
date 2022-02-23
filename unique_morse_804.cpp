//
// Created by 王月艺 on 2022/2/23.
//
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ms{".-","-...","-.-.","-..",".","..-.","--.","....","..",
                          ".---","-.-",".-..","--","-.","---",".--.",
                          "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> tslt;
        for(auto&s:words){
            string t;
            for(auto&c:s)
                t+=ms[c-'a'];
            tslt.insert(t);
        }
        return tslt.size();

    }
};