class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int preSum = 0;

        for(int i = 0; i < nums.size(); ++i){
            preSum += nums[i];
            int rem = preSum % k;
            if(rem == 0 && i > 0){ //i>0保证了子数组大小大于等于2
                return true;
            }else if(map.count(rem) != 0){ //证明存在这个数
                if(i - map[rem] >= 2){
                    return true;
                }
            }else{
                map.insert(make_pair(rem, i));
            }
        }

        return false;
    }
};
