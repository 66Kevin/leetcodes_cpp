#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int k = 0;
    while (cin >> k){
        vector<string> str;
        for (int i = 0; i < k; i++){
            string temp;
            cin >> temp;
            str.push_back(temp);
        }
        sort(str.begin(), str.end()); //#include <algorithm>
        for (int i = 0; i < k; i++){
            cout << str[i];
            if (i < k - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

