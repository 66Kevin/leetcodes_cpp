//
// Created by 王月艺 on 2022/2/16.
//
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 注意本题不能返回list，只能在list1中修改
        // 可以先把排序好的存到一个list中，最后把list1中的元素依次替换成sorted中的元素即可
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++]; // 整数数组没法push_back()，只能通过下表索引来添加
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }

    }
};