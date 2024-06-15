#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 
#define ld long double

const int md = 1e9;

void genSubsetSums(int start, int size, vector<ll> &arr, vector<ll> &res){
    
    for(int mask=0; mask<(1<<size); mask++){
        ll sum = 0;
        for(int i=0; i<size; i++){
            if(mask & (1<<i)) sum += arr[i+start];
        }
        res.push_back(sum);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<ll> lhs, rhs;
    genSubsetSums(0, n/2, arr, lhs);
    genSubsetSums(n/2, n-n/2, arr, rhs);

    sort(rhs.begin(), rhs.end());
    ll ans = 0;
    for(int i=0; i<lhs.size(); i++){
        ll li = lower_bound(rhs.begin(), rhs.end(), a-lhs[i]) - rhs.begin();
        ll ri = upper_bound(rhs.begin(), rhs.end(), b-lhs[i]) - rhs.begin();
        ans += ri-li;
    }
    cout << ans << endl;
    return 0;
}