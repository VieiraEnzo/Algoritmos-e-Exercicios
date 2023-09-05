#include <bits/stdc++.h>
using namespace std;
vector<int> rest;

int main(){
    int t;
    cin >> t;
    for(int i =0; i<t; i++){
        int quantas[10] ={0,0,0,0,0,0,0,0,0,0};
        rest.clear();
        int n,temp;
        cin >> n;
        for(int i =0; i < n; i ++){
            cin >> temp;
            if(quantas[temp % 10] >= 3){continue;}
            rest.push_back(temp % 10);
            quantas[temp%10] ++;
        }

        bool found = false;
        for(int i =0; i < rest.size()-2; i++){
            for(int j = i + 1; j < rest.size()-1; j ++){
                for(int k = j +1; k < rest.size(); k ++){
                    if((rest[i] + rest[j] + rest[k]) % 10 == 3){
                        found = true;
                    }
                }
            }
        }
        
        if(found){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
}