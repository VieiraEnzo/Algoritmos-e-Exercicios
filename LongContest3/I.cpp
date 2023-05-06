#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    long long int t,n,input;
    vector<long long int> vec;
    cin >>t;

    for (int init = 0; init < t; init++){

        vec.clear();
        cin >> n;
        
        //load vector
        for(int i =0; i< n; i++){
            cin >> input;
            vec.push_back(input);
        }

        int l = 0;
        for(int i =1; i < n; i++){
            if(vec[i] > vec[l]){
                break;
            }
            else{
                l = i;
            }
        }

        int r = n-1;
        for(int i = n-2; i >= 0; i--){
            if(vec[i] > vec[r]){
                break;
            }
            else{
                r = i;
            }
        }

        bool valey = true;
        if(r<=l){valey = true;}
        else{valey = false;}

        if(valey){cout << "YES" << endl;}
        else{cout << "NO" << endl;}

    }

}
