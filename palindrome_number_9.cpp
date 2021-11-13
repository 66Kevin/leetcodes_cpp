#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x<0 || (x % 10 == 0 && x != 0)){
        return false;
    }
    int res = 0;
    int num = x;
    while(x!=0){
        res=res*10 + x%10;
        x/=10;
    }
    return res==num;        
}

int main(){
    bool flag;
    flag = isPalindrome(10);
    cout << flag << endl;
}

