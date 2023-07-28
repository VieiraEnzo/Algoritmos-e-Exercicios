#include <bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;
    for(int i = 0; i < size; i ++){

        int part_num,temp;
        cin >> part_num;
        vector<int> people(part_num);
        vector<int> orig(part_num);
        for(int j =0; j < part_num; j ++){
            cin >> temp;
            people[j] = temp;
            orig[j] = temp;
        }
        sort(people.begin(),people.end());
        for(int j =0; j < part_num; j ++){
            if(orig[j] == people[part_num - 1]){cout << orig[j] - people[part_num - 2] << " ";}
            else{cout << orig[j] - people[part_num - 1]  << " ";}
        }
        cout << endl;
    }
}   
    
  
    

