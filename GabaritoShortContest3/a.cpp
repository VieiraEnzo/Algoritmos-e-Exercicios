#include <bits/stdc++.h>
using namespace std;
//prime ring

int n;
vector<int> ring;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};


bool check(int pos){
	for(int i = 0; i<pos; i++) if(ring[i] == ring[pos]) return false;
	if(pos < n-1) {
		return binary_search(primes.begin(), primes.end(), ring[pos-1]+ring[pos]);
	}
	return (binary_search(primes.begin(), primes.end(), ring[0]+ring[pos]) 
			and binary_search(primes.begin(), primes.end(), ring[pos-1]+ring[pos]));
}

void bt(int pos){
	if(pos == n){
		for (int i = 0; i<n-1; i++) cout << ring[i] << " ";
		cout << ring[ring.size()-1] << '\n';
	}
	for(int i = 2; i<=n; i++){
		ring[pos] = i;
		if(check(pos)){
			bt(pos+1);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int cnt = 0;
	while(cin >> n){
		if(cnt++) cout << "\n";
		cout << "Case " << cnt << ":\n";
		ring.resize(n);
		ring[0] = 1;
		bt(1);
	}
	return 0;
}