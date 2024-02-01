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

    int n, base;
    vector<T> pow, ha;

    Hashing(string &s, int a) : base(a), n(s.size()), pow(n+1), ha(n+1){

        pow[0] = 1;
        for(int i = 0; i< n; i++){
            ha[i + 1] = ((ha[i]*base)%m + s[i])%m;
            pow[i+1] = (pow[i] * base)%m; 
        }
    }

    int getRange(int a, int b){
        assert(a <= b);
        return (ha[b] - (ha[a] * base)%m)%m;
    }
};


void getAns(vector<map<int,int>> &count, Hashing<int> &stringHash, string &s){

    for(int tam = 0; tam< s.size(); tam++){
        for(int i = 0; i + tam < s.size(); i++){
            count[tam][stringHash.getRange(i, i + tam)]++;
        }
        if((*count[tam].begin()).second <= 1){
            cout << endl;
            return;
        }else{
            cout << (*count[tam].begin()).second << endl;
        }
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

        vector<map<int,int>> count(s.size());

        getAns(count, stringHash, s);
        
    }
        

}