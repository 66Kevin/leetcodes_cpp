#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s) {
    std::map<char,int> mymap;
    mymap['I'] = 1;
    mymap['V'] = 5;
    mymap['X'] = 10;
    mymap['L'] = 50;
    mymap['C'] = 100;
    mymap['D'] = 500;
    mymap['M'] = 1000;

    int ans = 0;

    for(int i=0;i<s.length();i++){
        if(mymap[s[i]] < mymap[s[i+1]]){
            ans -= mymap[s[i]];
        }else{
            ans += mymap[s[i]];
        }
    }
    return ans;
}



int main(){
    int res;
    res = romanToInt("LVIII");
    cout << res << endl;

}