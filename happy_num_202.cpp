#include<unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
 //用哈希表将每次数字的平方和存起来，判断某次结果是否曾经出现过，如果是说明进入了无限循环，变不成1，
    int find(int x){    //求一个数每个位置上的数字的平方和
        int res=0;
        while(x){
            res+=(x%10)*(x%10);
            x/=10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_map<int, int> hash;    //将每个答案存进哈希表，方便后续判断
        int t=find(n);
        while(t>1){ 
            if(hash.count(t))   //判断此结果是否在哈希表中出现过
            return false;
            hash.insert(t); //插入元素
            t=find(t);
        }

        return true;
    }
};