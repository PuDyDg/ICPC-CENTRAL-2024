#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e6+5;
int n;
int p[N], f[N];
int siz[N], cur[N];
vector <int> ad[N];
void dfs(int u) {
    siz[u] = 1;
    for (int v : ad[u]) {
        dfs(v);
        siz[u] += siz[v];
    }
}

bool check(int mid) {
    for (int i = 1 ; i <= n ; i++)
        cur[i] = 1;
    
    for (int i = n ; i >= 1 ; i--) {
        if (cur[i] * f[i] > mid) {
            
            int inc = (cur[i] * f[i] - mid + f[i] - 1) / f[i];
            cur[p[i]] += inc;
        }
    }

    return cur[1] * f[1] <= mid;

}   
signed main() {

    cin >> n;
    for (int i = 2 ; i <= n ; i++) {
        cin >> p[i];
        ad[p[i]].push_back(i);
    }

    dfs(1);

    for (int i = 1 ; i <= n ; i++) cin >> f[i];


    int l = 1, r = 1e18;
    int LIM = -1;

    while(l <= r) {
        int mid = (l + r) >> 1; 
        if (check(mid)) {
            LIM = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    int res = 0;
    for (int i = 1 ; i <= n ; i++)
        if (f[i] * siz[i] >= LIM) res++;
    cout << res;
    return 0;
}