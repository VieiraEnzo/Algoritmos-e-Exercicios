#include <bits/stdc++.h>
using namespace std;
int maxn = 3e6;
int mod = 1e9 + 7; int base = 33;
typedef unsigned long long ull;
static int C;

template<int M, class B> struct A{
int x;
B b;
A(int x=0) : x(x), b(x) {}
A(int x, B b) : x(x), b(b) {}
A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
explicit operator ull() { return x ^ (ull) b << 21; }
bool operator==(A o) const { return (ull)*this == (ull)o; }
bool operator<(A o) const { return (ull)*this < (ull)o; }
};

typedef A<100000007, A<100000009, unsigned> > H;

struct Hashing{
int n;
    vector<H> ha, pw;
        Hashing(string& str) : n((int)str.size()), ha(n+1), pw(n+1){
        pw[0]=1;
        for(int i=0; i<n; i++){
        ha[i+1] = ha[i] * C + str[i],
        pw[i+1] = pw[i] * C;
        }
        }
        H range(int a, int b){ // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};


int main(){

    string a; cin >> a ;
    int t; cin >> t;
    Hashing h(a);



    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << (ull) h.range(min(b,a),max(b,a)) << endl;
    }
    
}