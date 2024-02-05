#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr), ios_base::sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();
    string s2;
    for(int i = 0; i< n; i++){
        if(s[i] =='a' ||s[i] =='e' ||s[i] =='i'|| s[i] =='o' || s[i] =='u'){
            s2.push_back(s[i]);
        }
    }   

    int l = 0;
    int r = s2.size() -1;
    bool resp = true;
    while (l < r)
    {
        if(s2[l] != s2[r]){
            resp = false;
        }
        l++;r--;
    }
    

    if(resp) cout << 'S' << endl;
    else cout << 'N' << endl;
}