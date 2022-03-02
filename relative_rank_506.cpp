#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> arr;
        for (int i=0; i<n; ++i){
            arr.push_back(make_pair(score[i], i));
        }
        sort(arr.rbegin(), arr.rend()); //反向迭代器
        vector<string> ans(n);
        for (int i=0;i<n;i++){
            if (i<3){
                ans[arr[i].second] = rank[i];
            }else{
                ans[arr[i].second] = to_string(i+1);
            }
        }
        return ans;
    }
};