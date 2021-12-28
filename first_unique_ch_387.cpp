#include<unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> hashmap;

        for(auto ch : s){
            hashmap[ch] +=1;
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); ++it){ 
            cout << char(it->first) << endl;
        }

        for(int i = 0; i < s.size(); ++i){
            if(hashmap[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    string tmp = "leetcode";
    Solution sol;
    int res = sol.firstUniqChar(tmp);
    cout << res << endl;
}