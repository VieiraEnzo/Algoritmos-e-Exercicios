#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n, max;
    cin >>t;
    for (int init = 0; init < t; init++){
        string s;
        cin >> n >> s;
        max = s[0] - 'a';
        for (int i =1; i < n; i ++){
            if(s[i] - 'a' > max){
                max = s[i]- 'a';
            }
        }
        cout << max + 1 << endl;
    }

}
