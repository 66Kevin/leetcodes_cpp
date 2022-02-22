//
// Created by 王月艺 on 2022/2/22.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max_candies = 0;
        for(auto i : candies){
            if(i > max_candies){
                max_candies = i;
            }
        }

        for(auto i : candies){
            if(abs(i - max_candies) <= extraCandies){
                result.push_back(1);
            }else{
                result.push_back(0);
            }
        }

        return result;
    }
};