class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MIN && b==-1) return INT_MAX;// 题目要求-2147483648/-1 = 2147483647返回最大值
        int sign = (a>0)^(b>0) ? -1:1;//a>0和b>0异或，若为真，则异号，返回-1，若为假，则同号，返回1
        //sign最先写，不然a,b值就改变了
        if(a>0) a=-a;
        if(b>0) b=-b;
        int res = 0;
        while(a<=b){//改成<=
            int val = b;//记录除数
            int k = 1;
            // 0xc0000000 是十进制 -2^30 的十六进制的表示
            // 判断 value >= 0xc0000000 的原因：保证 value + value 不会溢出
            // 可以这样判断的原因是：0xc0000000 是最小值 -2^31 的一半，
            // 而 a 的值不可能比 -2^31 还要小，所以 value 不可能比 0xc0000000 小
            // -2^31 / 2 = -2^30
            while(val >= 0xc0000000 && a<=val+val){
                val += val;
                // 代码优化：如果 k 已经大于最大值的一半的话，那么直接返回最小值
                // 因为这个时候 k += k 的话肯定会大于等于 2147483648 ，这个超过了题目给的范围
                if (k > INT_MAX / 2) {
                    return INT_MIN;
                }
                k += k;
            }
            a -= val;
            res += k;
        }
        return sign==1 ? res:-res;
    }

};
