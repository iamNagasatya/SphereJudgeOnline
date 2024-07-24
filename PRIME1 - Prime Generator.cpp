/* 
https://www.spoj.com/problems/PRIME1/
Author : iamNagasatya 
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int maxPrime = 1e5 + 1;
bitset<maxPrime> isprime;
vector<int> primes;

ll m, n;
bitset<maxPrime> ss;

void sieve(){
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i=2; i<=maxPrime; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=maxPrime; j+=i){
                isprime[j] = 0;
            }
        }
    }
}

void solve(){
    ss.set();
    for(auto &p : primes){
        if(p*p > n) break;

        ll start = (m/p)*p;
        if(p>=m) start = 2*p;
        
        for(ll j= start; j<=n; j+=p){
            if(j<m) continue;
            ss[j-m] = 0;
        }
    }

    for(ll i=m; i<=n; i++){
        if(ss[i-m] && i!=1) cout << i << endl;
    }
}



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        solve();
        cout << endl;
    }    

    return 0;
}