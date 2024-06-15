#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> lhs;
    vector<int> rhs;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                lhs.push_back(arr[i]*arr[j]+arr[k]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(arr[i]!=0) rhs.push_back(arr[i]*(arr[j]+arr[k]));
            }
        }
    }

    sort(rhs.begin(), rhs.end());
    int ans = 0;
    for(int i=0; i<lhs.size(); i++){
        int x = lhs[i];
        int li = lower_bound(rhs.begin(), rhs.end(), x) - rhs.begin();
        int ui = upper_bound(rhs.begin(), rhs.end(), x) - rhs.begin();
        ans += ui-li;
    }

    cout << ans << endl;

    return 0;
}