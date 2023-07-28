#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int init = 0; init < n; init ++){
        int size;
        cin >> size;
        vector <int> num(size);
        for(int i =0; i < size; i ++){
            cin >> num[i];
        }

        int pos_big_0 = size + 1,pos_low_1 = size + 1;
        for(int i = 0; i < size; i ++){
            if(num[i] == 0){
                pos_big_0 = i;
                break;}
        }

        for(int i = size - 1; i >=0; i --){
            if(num[i] == 1){pos_low_1 = i;break;}
        }

        int num_0 =0,num_1= 0;

        for(int i =0; i < size; i ++){
            if(num[i] == 0){num_0++;}
            else{num_1++;}
        }

        int max = (num_0-1) - pos_big_0;
        int max2;
        int num_1_esquerda = 0;
        int num_0_direita = 0;
        for(int i = pos_low_1 - 1; i >= 0; i--){
            if(num[i] == 1){num_1_esquerda++;}
        }
        for(int i = pos_low_1 + 1; i <size; i++){
            if(num[i] == 0){num_0_direita++;}
        }
        max2 = num_1_esquerda - num_0_direita;
        
        if(max > max2){num[pos_big_0] = 1;}
        else{num[pos_low_1] = 0;}

        for(auto a : num){
            cout << a << " ";
        }
        cout << endl;

        //calculate inversions
        int pos_big_1 = size + 1;
        for(int i =0; i < size; i ++){
            if(num[i] == 1){pos_big_1 = i;break;}
        }

        int count = 0;
        for(int i = pos_big_1; i < size; i ++){
            if(num[i] == 0){count ++;}
        }

        int inversions = count;
        for(int i = pos_big_1 +1; i < size; i ++){
            if(num[i] == 0){count--;}
            else{inversions += count;}
        }

        cout << inversions << endl;
    }
}   
    