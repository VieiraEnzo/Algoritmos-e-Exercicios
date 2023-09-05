#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, Q;
    int input;
    cin >>n >> Q;
    vector<int> numbers;

    for(int i = 0; i <n; i ++){
        cin >> input;
        numbers.push_back(input);
    }

    for(int i = 0; i < Q; i ++){
        cin >> input;
        if(*lower_bound(numbers.begin(), numbers.end(), input) == input)
             cout << lower_bound(numbers.begin(), numbers.end(), input) - numbers.begin() << endl;
        else{
            cout << -1 << endl;
        }

    }

    
}
