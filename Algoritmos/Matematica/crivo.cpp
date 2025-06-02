const int maxn = 1e7+1;
vector<int> sieve(maxn);

void build(){
    for(int i = 2; i < maxn; i++){
        if(sieve[i]) continue;
        for(int j = 0; i*j < maxn; j++){
            if(sieve[i*j]) continue;
            sieve[i*j] = i;
        }
    }
}
 
vector<int> primes;
void fact(int x){
    if(x == 1) return;
    primes.push_back(sieve[x]);
    fact(x/sieve[x]);
}