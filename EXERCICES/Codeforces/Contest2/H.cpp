#include <bits/stdc++.h>
 
using namespace std ;
 
int main(){
    
    string s ;
    int n ; cin >> n ;
 
    cout << "Start test" << endl << flush ;
    fflush(stdout) ;
 
    for( int i = 0 ; i < n ; i++ ){
        getline(cin,s) ; 
        getline(cin,s) ; 
        getline(cin,s) ; 
        cout << 'A' << endl << flush ;
        fflush(stdout) ;
    }
 
    getline(cin,s) ;
    int mark = s[13] - '0';
    if( mark < 3 )
 
    cout << "Start test" << endl << flush ;
    fflush(stdout) ;
 
    for( int i = 0 ; i < n ; i++ ){
        getline(cin,s) ; 
        getline(cin,s) ;
        getline(cin,s) ;  
        cout << 'B' << endl << flush ;
        fflush(stdout) ;
    }
 
    getline(cin,s) ;
 
}
