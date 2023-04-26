#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin >> t;

    for(int init = 0; init < t; init ++){

        cin >>n;
        long long int b[n-1];
        long long int answer[n];
        for(int i=0; i<n-1; i++){
            cin >> b[i];
        }

        for(int i=0; i<n-2; i++){
            if(b[i]<b[i+1]){
                answer[i+1] = b[i];
            }
            if(b[i]==b[i+1]){
                answer[i] = b[i];
                answer[i+1] = b[i+1];
                
            }
            else{
                answer[i] = b[i];
                answer[i+1] = 0;
            }
        }

    }
}
