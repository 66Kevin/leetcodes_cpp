
class Solution {        
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int r = arr.size() - 1;         // 右端点
        int l = 0;                      // 左端点
        while(r - l + 1 > k) {          // 两个指针往中间移动
            if(abs(arr[r] - x) >= abs(arr[l] - x)) {
                r--;
            }
            else {
                l++;
            }
        }
        for(int i = 0; i < k ; i++) {       // 剩下的就是符合条件的
            ans.emplace_back(arr[l++]);
        }
        return ans;
    }
};

