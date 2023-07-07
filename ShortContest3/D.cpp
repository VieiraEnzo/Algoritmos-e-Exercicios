#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i =0; i < t; i ++){
        int n;
        cin >> n;
        vector<int> array(n);
        map<int,int>save;
        for(int i =0 ; i < n; i ++){
            cin >> array[i];
        }

        // save[array[n-1]] = 0;
        // for(int i = n-2; i >= 0; i --){
        //     for(int j = i+1; j > n; j ++){
        //         if(array[i] > array[j]){
        //             save[array[i]] = save[array[j]]+1;
        //             cout << array[i] << " é maior que " << array[j] << endl;
        //         }
        //         else if(j == array.size()-1){save[array[i]] = 0;}
        //     }
        // }
        // int total = 0;
        // for(int num : array){
        //     total += save[num];
        // }
        // cout << total << endl;
        int count = 0;
        for(int i =0; i < n-1; i ++){
            for(int j =i ; j < n;j ++){
                if(array[i] > array[j]){
                    count ++;
                }
            }
        }
        cout << count << endl;
    }   
}