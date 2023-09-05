#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    cin >> t;

    for(int i = 0;i < t; i++){
        long long int n,d;
        string number;
        cin >> n >> d >> number;
        
        int insert_place = n;
        for(int i = 0;i < n;i++){
            if(number[i] -'0' < d){insert_place = i;break;}
        }

        if(insert_place != n){
            number.insert(insert_place, 1 , d+'0');
        }
        else{
            number.push_back(d+'0');
        }
        cout << number << endl;
    }

}
