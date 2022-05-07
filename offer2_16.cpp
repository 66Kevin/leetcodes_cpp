class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) return 1;
        if (n == -1) return 1.0 / x;
        
        double half = myPow(x, n>>1); ////右移代替除以2

        if (n & 1){ //奇数
            return half * half * x;
        }else{ //偶数
            return half * half;
        }
    }
};

