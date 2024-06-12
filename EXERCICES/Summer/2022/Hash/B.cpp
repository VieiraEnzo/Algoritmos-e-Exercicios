#include <bits/stdc++.h>
using namespace std; 

const unsigned int m = 1e9 + 7;

// template<unsigned M> struct modnum{
//     unsigned x; using num = modnum;
//     num& norm(int a){return a.x % M;}
//     operator+ (num &a){return norm(a.x + x);}
//     operator* (num &a){return norm(a.x * x);}
// };



template<typename T> struct Hashing{
    int base, n;
    vector<T> pow, ha; 

    Hashing(string & s, int a) : n(s.size()), base(a) ,pow(n+1), ha(n+1){

        pow[0] = 1;
        for(int i = 0; i < n; i++){
            ha[i + 1] = ha[i] * base + s[i];
            pow[i+1] = pow[i] * base;
        }

    }

    T getRange(int a, int b){
        assert(a <= b);
        return ha[b] - ha[a] * pow[b-a];

    }
};


void getAns(vector<map<int,int>> &count, Hashing<int> &stringHash, string &s){

    for(int tam = 1; tam <= s.size(); tam++){
        for(int i = 0; i + tam <= s.size(); i++){
            count[tam][stringHash.getRange(i, i + tam)]++;
        }

        //findMaxEl
        int maxEl = 0;
        for(auto it = count[tam].begin(); it!= count[tam].end(); it++){
            maxEl = max(maxEl, (*it).second);
        }

        if(maxEl <= 1){
            cout << endl;
            return;
        }else{
            cout << maxEl << endl;
        }
        // cout << stringHash.getRange(0, 2) << endl;
        // cout << stringHash.getRange(1, 3) << endl;
        // for(auto [a,b] : count[tam]){
        //     cout << b  << " ";
        // }cout << endl;
    }
}



int main(){

    const int base1 = 53;

    // using num = modnum<hash1>;
    


    string s;
    while (getline(cin ,s))
    {
        string s2; 
        for(int i = 0; i< s.size(); i++){
            if(s[i] != ' '){
                s2.push_back(s[i]);
            }
        }

        Hashing<int> stringHash(s2, base1);

        vector<map<int,int>> count(s.size() + 1);

        getAns(count, stringHash, s);
        
    }
        

}