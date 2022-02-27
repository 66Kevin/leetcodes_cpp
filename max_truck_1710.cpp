//
// Created by 王月艺 on 2022/2/27.
//
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:

    static bool cmp1(const vector<int>& a, const vector<int> & b)
    {
        return a[1] < b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), cmp1);       //根据箱子容量，升序排序
        int res = 0;

        for (int i = boxTypes.size()-1; i >=0; i--)
        {
            int cnt = std::min(truckSize, boxTypes[i][0]);  //当前可以装的箱子数
            truckSize -= cnt;
            res += cnt * boxTypes[i][1];
            if (truckSize == 0)
                break;
        }
        return res;
    }
};