class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue = INT_MIN, tmpMax = 1, tmpMin = 1;

        for (int i = 0; i < nums.size(); ++ i)
        {
            if (nums[i] < 0)                            //遇到负元素是交换最大最小值
            {
                swap(tmpMax, tmpMin);
            }

            tmpMax = max(tmpMax * nums[i], nums[i]);    //考虑到情况1
            tmpMin = min(tmpMin * nums[i], nums[i]);    //考虑到情况3

            maxValue = max(maxValue, tmpMax);           //每个循环更新最大值
        }

        return maxValue;
    }
};
