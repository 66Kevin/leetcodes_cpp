class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int i, int j){
            string istr = to_string(i);
            string jstr = to_string(j);
            return istr + jstr > jstr + istr;
        });
        string res;
        for (int num:nums) {
            res += to_string(num);
        }

        if (res[0] == '0'){
            return "0";
        }else{
            return res;
        }
    }
};

