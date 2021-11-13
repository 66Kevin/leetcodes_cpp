#include <iostream>
using namespace std;

int main(){
    int a = 13456;

    cout << a%10 << endl;

    int res = 0;
    while(a!=0){
        if(res>INT32_MAX%10 || res<INT32_MIN%10){
            return 0;
        }
        res = (res*10) + (a % 10);
    }
}