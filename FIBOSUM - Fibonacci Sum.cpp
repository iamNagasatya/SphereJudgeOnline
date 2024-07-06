#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int sz = 2;

struct Mat{
    int m[sz][sz];
    
    Mat(){
        memset(m, 0, sizeof(m));
    }
    
    void identify(){
        for(int i=0; i<sz; i++){
            m[i][i] = 1;
        }
    }
    
    Mat operator*(Mat &o){
        Mat ans;
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                for(int k=0; k<sz; k++){
                    ans.m[i][j] += m[i][k] * o.m[k][j];
                    ans.m[i][j] %= mod;
                }
            }
        }
        return ans;
    }
};

int fibo(int n){
    if(n<1) return 0;
    if(n==1) return 1;
    n -= 2;

    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    Mat res;
    res.identify();
    while(n){
        if(n&1){
            res = res * T;
        }
        T = T*T;
        n >>= 1;   
    }

    return (res.m[0][1] + res.m[0][0])%mod;

}

int32_t main() {

    int t;
    cin >> t;
    int n, m;

    while(t--){
        cin >> n >> m;
        cout << (fibo(m + 2) - fibo(n + 1) + mod) % mod << '\n';
    }
    
    return 0;
}
