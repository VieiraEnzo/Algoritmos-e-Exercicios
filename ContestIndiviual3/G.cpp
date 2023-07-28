#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,size;
    cin >> n;
    for(int init = 0; init < n; init ++){
        cin >> size;
        vector<int> arr(size);
        for(int i = 0; i < size; i ++){
            cin >> arr[i];
        }
        int l = 0,r = size-1;

        for(int i = 1; i < size ;i ++){
            if(arr[l] >= arr[i]){
                l = i;
            }
            else{
                break;
            }
        }

        for(int i = size -2; i >=0 ;i --){
            if(arr[r] >= arr[i]){
                r = i;
            }
            else{
                break;
            }
        }

        bool yes = true;
        for(int i =min(l,r); i < max(l,r); i ++){
            if(arr[i] != arr[i+1]){
                yes = false;
            }
        }

        if(yes){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }   
}
  
    

