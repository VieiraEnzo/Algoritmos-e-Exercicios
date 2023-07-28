#include <bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;
    int arr[3];
    for(int i = 0; i < size; i++){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        cout << arr[1] << endl;
    }
}   
    
  
    

