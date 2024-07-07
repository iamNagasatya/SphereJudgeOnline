#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

int md = 1e9;

string a, b;

ll memo[2001][2001];

ll dp(ll i, ll j){
    if(i==a.size() && j==b.size()) return 0;
    if(i==a.size()) return b.size()-j;
    if(j==b.size()) return a.size()-i;

    if(memo[i][j]!=-1) return memo[i][j];

    if(a[i]==b[j]) return  memo[i][j] =  dp(i+1, j+1);
    return memo[i][j] =  1 + min({dp(i+1, j+1), dp(i, j+1), dp(i+1, j)});
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        cin >> a >> b;
        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0) << endl;
    }

    return 0;
}