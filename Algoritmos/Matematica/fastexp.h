//Algoritmo para calcular a exponenciação rápida de um número
//Complexidade: O(log e), onde e é o expoente

ll fastexp(ll b, ll e, ll mod){
    ll res = 1;
    while (e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return res;
}
