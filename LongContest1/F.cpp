#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,ac=0,wa=0,re=0,tle=0;
    string output;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> output;
        if (output == "AC"){
            ac++;
        }
        else if (output == "WA"){
            wa++;
        }
        else if (output == "RE"){
            re++;
        }
        else{
            tle++;
        }
    }
    cout << "AC x " << ac << endl;
    cout << "WA x " << wa << endl;
    cout << "TLE x " << tle << endl;
    cout << "RE x " << re << endl;
}
