class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        for(int i=0; i <= n; ++i){
            int num = countBit(i);
            result.push_back(num);
        }
        return result;
    }
private:
    int countBit(int n){
        int count = 0;
        while(n){
            if(n & 1) count++;
            n = n >> 1;
        }

        return count;
    }
};
