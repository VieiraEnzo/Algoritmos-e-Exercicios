#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    if((n%2)==0 && (n/2)%2) {cout << "NO";return 0;}
    if(n%2 && ((n/2)+1)%2) {cout << "NO";return 0;}

    cout << "YES" << endl;
            cout << (n/2) << endl;
            int a = n;
            int b = 1;
            while (a > 0)
            {
                cout << a << " ";
                if(b){a-=3;}
                else{a-=1;}
                b= (b+1)%2;
            }
            cout << endl;

            if(n%2)cout << (n/2)+1 <<endl;
            else cout << (n/2) <<endl;
            a = n-1;
            b = 0;
            while (a > 0)
            {
                cout << a << " ";
                if(b){a-=3;}
                else{a-=1;}
                b= (b+1)%2;
            }
            cout << endl;
    

}