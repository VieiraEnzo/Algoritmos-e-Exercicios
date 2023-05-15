#include <bits/stdc++.h>
#include <vector>
using namespace std;

int bSearch(vector<long long int> &v, int e, int d, long long int x) {
   while (e <= d) {
       int m = (e + d)/2;
       if (v[m] == x)
           return m;
       if (v[m] < x)
           e = m + 1;
       else
           d = m - 1;
   }
   return -1;
}


int main(){
    long long int n;
    long long int x;
    long long int input;
    vector<long long int> numbers;
    vector<long long int> numbers_origin;
    cin >> n >> x;

    for(int i=0;i<n;i++){
        cin >> input;
        numbers.push_back(input);
        numbers_origin.push_back(input);
    }

    sort(numbers.begin(), numbers.end());

    int result_j = -1;
    int result_i = -1;
    for(int i =0; i < n; i ++){
        long long int complement = x - numbers[i];
        result_j = bSearch(numbers,0,numbers.size(), complement);
        result_i = i;
        if(result_j != -1){break;}
    }

    if(result_j == -1){cout << -1;}
    else{
        int printed;
        for(int i = 0; i <n; i ++){
            if(numbers_origin[i] ==  numbers[result_i]){
                printed = i;
                cout << i + 1 << ' ';
                break;
            }
        }
        for(int i =0; i <n; i ++){
            if(numbers_origin[i] ==  numbers[result_j] && i != printed){
                cout << i + 1 << endl;
                break;
            }
        }
    }
    
}