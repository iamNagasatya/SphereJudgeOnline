#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9;

ll n, k;

ll b[11], c[11];

struct Mat {
    ll sz;
    ll m[11][11];
    Mat(ll k){
        this->sz=k;
        memset(m, 0, sizeof(m));
    }

    void identity(){
        for(int i=0; i<sz; i++){
            m[i][i]=1;
        }
    }

    Mat operator*(Mat &B){
        Mat R(sz);
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                for(int k=0; k<sz; k++){
                    R.m[i][j]+= (m[i][k] * B.m[k][j] * 1LL);
                    R.m[i][j]%=md;
                }
            }
        }
        return R;
    }

};

ll solve(){
    if(n<=k) return b[n-1];
    Mat T(k), res(k);
    res.identity();

    for(int i=0; i<k; i++){
        T.m[0][i] = c[i];
    }
    for(int i=1; i<k; i++){
        T.m[i][i-1] = 1;
    }

    n-=k;
    while(n){
        if(n&1) res = res*T;
        T = T*T;
        n>>=1;
    }

    ll ans=0;
    for(int i=0; i<k; i++){
        ans += (res.m[0][i]*b[k-i-1]*1LL);
        ans %= md;
    }

    return ans;

    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> k;
        for(int i=0; i<k; i++){
            cin>>b[i];
        }
        for(int i=0; i<k; i++){
            cin>>c[i];
        }
        cin >> n;
        cout << solve() << endl;
    }
    
    return 0;
}