class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e+9; 
        while(r > l){
            int mid = l + r >> 1; 
            if(check(piles, mid, h)){
                r = mid;
            }else{
                l = mid + 1; 
            }
        }
        return r; 
    }

    // 判读速度为k时, 所花费的时间是否小于等于规定的时间h 
    bool check(vector<int> &piles, int k, int h){
        int sum = 0; 
        for(auto v : piles) {
            if(v % k) ++sum;
            sum += v / k; 
        }
        return sum <= h; 
    }
};

