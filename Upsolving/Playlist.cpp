#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int n; cin >> n;
    int arr[n];
    for(int i =0; i < n; i ++) cin >> arr[i];
    set<int> s;
    int answ = 0;

    for(int l =0, r =0; r < n; r++){
        if(s.count(arr[r])){
            while (arr[l] != arr[r])
            {
                s.erase(arr[l]);
                l++;
            }
            l++;
        }
        else{
            s.insert(arr[r]);
        }
        answ = max(answ, (int)s.size());
    }
    cout << answ;

}
    

