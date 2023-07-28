#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool f = true;
		for(int i = 1; i<s.size(); i++) if(s[i] != s[i-1]) f = false;
		if(f) cout << "-1\n";
		else cout << s.size()-1 << '\n';
	}
	return 0;
}