//
// Created by 王月艺 on 2022/2/13.
//
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;

        auto insert = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                ++freq[move(word)];
            }
        };

        insert(s1);
        insert(s2);

        vector<string> ans;
        for (const auto& [word, occ]: freq) {
            if (occ == 1) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};