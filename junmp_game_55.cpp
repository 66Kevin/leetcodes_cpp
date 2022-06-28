class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i=0; i<nums.size(); ++i){
            if(i > reach) return false; //表示已经遍历i超出了所能到达的最远地方reach
            reach = max(reach, nums[i]+i);
        }
        return true;
    }  
};
