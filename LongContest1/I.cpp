#include <bits/stdc++.h>
using namespace std;

int main(){
    string problem;
    cin >> problem;
    int Sz = problem.size();
    long long int sum = 0;
    for(int i = 0; i < Sz; i ++){
        sum += (problem[i] - 'A' + 1) * pow(26, (Sz - i - 1));
    }
    cout << sum;
}
