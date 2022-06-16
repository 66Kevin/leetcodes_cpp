class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> ans;

        while(numbers[l] + numbers[r] != target){
            if(numbers[l] + numbers[r] < target){
                l++;
            }else if(numbers[l] + numbers[r] > target){
                r--;
            }
        }

        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
};
