#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const int maxPrime = 86028122;

bitset<maxPrime> isprime;

void sieve(vector<int> &primes){
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


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> primes;
    sieve(primes);
    int t; cin >>t;
    int k;
    while(t--){
        cin >> k;
        cout << primes[k-1] << endl;
    }

    return 0;
}
