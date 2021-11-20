#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.size();
        if(n<=0) return 0;

        int res = 0;
        for (int i = n-1; i>=0 ; --i)
        {
            if(s[i]==' '){
                if (res != 0){
                    return res;
                }
                continue;
            }else{
                res+=1;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
}