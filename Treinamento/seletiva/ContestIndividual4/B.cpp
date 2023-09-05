#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string input;
    string rinput;
    set <string> num;
    for(int init = 0; init < n; init ++){
        cin >> input;
        rinput = input.substr();
        reverse(rinput.begin(),rinput.end());
        if(num.count(input) == 0 && num.count(rinput) == 0){
            num.insert(input);
        }
    }
    cout << num.size() << endl;
}
    

