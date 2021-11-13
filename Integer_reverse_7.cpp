#include <iostream>
#include <vector>
#include <string>

using namespace std;

int reverse(int x) {
    int res = 0;
    while(x!=0){
        // Max = 2147473647
        if(res>INT32_MAX/10 || res<INT32_MIN/10){
            return 0;
        }
        res = (res*10) + (x%10);
        x/=10;
        cout << x << endl;
    }
    return res;
}


int main()
{
    int res;
    res = reverse(2147483641);
    cout << res << endl;
}