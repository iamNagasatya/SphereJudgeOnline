#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'


struct segment_tree{
    vector<int> st, lazy;
    int n;

    void init(int _n){
        this->n = _n;
        st.resize(4*_n, 0);
        lazy.resize(4*_n, 0);
    }
    
    void build(int start, int end, int node, vector<int> &arr){
        if(start==end){
            st[node] = arr[start];
            return;
        }
        int mid = start + (end-start)/2;
        build(start, mid, 2*node+1, arr);
        build(mid+1, end, 2*node+2, arr);
        st[node] = st[2*node+1] + st[2*node+2];
    }

    void build(vector<int> &arr){
        build(0, n-1, 0, arr);
    }


    int query(int start, int end, int node, int l, int r){
        if(end < l || r < start) return 0;
        
        if(lazy[node]!=0){
            st[node] += lazy[node] * (end-start+1);
            if(start!=end){
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if(l <= start && end <= r){
            return st[node];
        }

        int mid = start + (end-start)/2;
        int q1 = query(start, mid, 2*node+1, l, r);
        int q2 = query(mid+1, end, 2*node+2, l, r);

        return q1 + q2;
        
    }

    int query(int l, int r){
        return query(0, n-1, 0, l, r);
    }

    void add(int start, int end, int node, int idx, int val){
        if(start==end && start==idx){
            st[node] += val;
            return;
        }

        int mid = start + (end-start)/2;

        if(idx<=mid){
            add(start, mid, 2*node+1, idx, val);
        }
        else{
            add(mid+1, end, 2*node+2, idx, val);
        }
        
        st[node] = st[2*node+1] + st[2*node+2];

    }

    void add(int idx, int val){
        add(0, n-1, 0, idx, val);
    }

    void add(int start, int end, int node, int l, int r, int val){
        if(end < l || r < start) return;

        if(lazy[node]!=0){
            st[node] += lazy[node] * (end-start+1);
            if(start!=end){
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if(l<=start && end <= r){
            st[node] += val*(end-start+1);
            if(start!=end){
                lazy[2*node+1] += val;
                lazy[2*node+2] += val;
            }
            return;
        }

        int mid = start + (end-start)/2;

        add(start, mid, 2*node+1, l, r, val);
        add(mid+1, end, 2*node+2, l, r, val);

        st[node] = st[2*node+1] + st[2*node+2];
    }

    void add(int l, int r, int val){
        add(0, n-1, 0, l, r, val);
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    segment_tree tree;

    int n, m, w;
    cin >> n >> m >> w;
    
    tree.init(w);
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        tree.add(x, y, 1);
    }
    int q;
    for(int i=0; i<m; i++){
        cin >> q;
        cout << tree.query(q, q) << endl;
    }

    return 0;
}
