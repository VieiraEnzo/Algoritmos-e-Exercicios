#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a;
    cin >> a;
    for(int init = 0; init < a; init ++){
        long long int n,c,d;
        cin >> n >> c >> d;
        vector<int> arr(n);
        for(int i =0; i < n;i ++){
            cin >> arr[i];
        }

        sort(arr.rbegin(),arr.rend());
        if(arr[0] >= c){
            cout << "Infinity" << endl;
            continue;;
        }

        long long int k =1;
        while (true)
        {
            long long int coins = 0;
            for(long long int i =0; i <= d; i ++){
                long long int quest = i%k;
                if(quest >= n){coins += 0;}
                else{coins+= arr[quest];}
            }
            if(coins < c){k-=1;break;}
            k++;
        }
        if(k == -1){
            cout << "Impossible" << endl;
        }
        else{
            cout << k << endl;
        }
        
    }   
}
  
    
