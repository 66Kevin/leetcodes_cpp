#include<unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        unordered_map<char, int> hashmap_s;
        unordered_map<char, int> hashmap_t;

        if(len_s != len_t){
            return false;
        }

        for(int i=0; i<len_s; ++i){
            hashmap_s[s[i]] +=1;
            hashmap_t[t[i]] +=1;
        }

        for(auto i = hashmap_s.begin(); i != hashmap_s.end(); ++i){
            if((!hashmap_t.count(i->first)) || (hashmap_s[i->first] != hashmap_t[i->first]) ){
                return false;
            }
        }
        return true;
    }
};