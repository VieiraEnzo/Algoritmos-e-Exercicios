#include <bits/stdc++.h>
using namespace std;


int main(){
    int n = 0,s,m;
    int array[50];
    cin >> n;

    for(int i = 0 ; i < n; i ++){
        cin >> m >> s;
        for(int j = 0; j < m;j++){
            cin >> array[j];
        }
        
        // order the array
        int temp;
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m;j++){
                if(array[j] < array[i]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    }
            }
        }


        int k = 0;
        bool found = false;
        while(s > 0){
            k++;
            found = false;
            for(int i=0; i < m; i++){
                if(k == array[i]){
                    found = true;
                    break;}
                if(k < array[i]){break;}
            }
            if(!found){
                s-=k;}
        }


        bool complete = true;
        int first_up_k;
        if(k < array[m-1]){
            for(int i = 0 ; i < m; i++){
                if(k < array[i]){
                    first_up_k = i;
                    break;
                }
            }
            if(array[first_up_k] - k == 1){
                for(int i = first_up_k;i <m-1; i++){
                    if(array[i+1]- array[i] != 1){
                        complete = false;
                    }
                }
            }
            else{complete = false;}
        }


        if(s == 0 && complete){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
