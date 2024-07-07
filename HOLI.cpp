// https://www.spoj.com/problems/HOLI/
// Author : iamNagasatya

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

int md = 1e9;
const int maxN = 1e5 + 1;

vector<vector<pair<int, int>>> gr;

int dfs(const int cur, const int par, ll &res, const int n){
    int nodes = 1;
    for(auto x : gr[cur]){
        if(x.first != par){
            const int wt = x.second;
            const int child_nodes = dfs(x.first, cur, res, n);
            res += 2 * min(child_nodes, n-child_nodes) * wt * 1LL;
            nodes += child_nodes;
        }
    }
    return nodes;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t, tcnum = 0;
    cin >> t;
    int n, x, y, z;
    while(t--){
        cin >> n;
        gr.clear();
        gr.resize(n+1, vector<pair<int, int>>());
        for(int i=0; i<n-1; i++){
            cin >> x >> y >> z;
            gr[x].push_back({y, z});
            gr[y].push_back({x, z});
        }
        ll ans = 0;
        dfs(1, 0, ans, n);
        cout << "Case #" << ++tcnum <<": " << ans << endl;
        
    }

    return 0;
}