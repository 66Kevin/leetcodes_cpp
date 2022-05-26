class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 1, res = 0;
        sort(nums.begin(), nums.end());
        while(right < n && left < n){
            if(left == right | nums[right] - nums[left] < k){
                right++;
            }else if(nums[right] - nums[left] > k){
                left++;
            }else{
                res++;
                left++;
                while(left < n && nums[left] == nums[left-1]) left++;
            }
        }
        return res;
    }
};


