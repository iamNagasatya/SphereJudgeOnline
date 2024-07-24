// https://www.spoj.com/problems/ADARAIN/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, w;
    cin >> n >> m>> w;

    vector<int> arr(w+1, 0);
    int l, r;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        ++arr[l]; --arr[r+1];
    }
    for(int i=1; i<w; i++){
        arr[i] += arr[i-1];
    }
    int q;
    for(int i=0; i<m; ++i){
        cin >> q;
        cout << arr[q] << endl;
    }

    return 0;
}
