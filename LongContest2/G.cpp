#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    int a,b,c,x,y;
    cin >> t;
    pair <int,int> rest;
    
    for(int i = 0;i < t; i++){

        cin >> a >> b >> c >> x >> y;
        if((a-x) >= 0){rest.first = 0;}
        else{rest.first = (x-a);}
        if((b-y) >= 0){rest.second = 0;}
        else{rest.second = (y-b);}

        if(rest.first + rest.second <= c){
            cout <<"YES"<<endl;
        }
        else{
            cout << "NO" << endl;
        }

    }


}
