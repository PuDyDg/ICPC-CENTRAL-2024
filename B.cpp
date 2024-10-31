#include "bits/stdc++.h"
#define pii pair <int, int>
#define fi first
#define se second

using namespace std;

const int N = 5005;
int n;
long long k;
int a[N];
vector <pii> p;
int cnt[(1 << 20)];
int op[(1 << 20)];
long long F[(1 << 20)];
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++) {
            p.push_back(pii(i, j));
            cnt[a[i] & a[j]]++;
        }
    
    for (int mask = 0 ; mask < (1 << 20) ; mask++)  {
        for (int i = 0 ; i < 20 ; i++)
            if ((mask & (1 << i)) == 0) op[mask] += (1 << i);
    }
    
    for(int i = 0; i<(1<<20); ++i)
        F[i] = cnt[i];
    for(int i = 0;i < 20; ++i) for(int mask = 0; mask < (1<<20); ++mask)
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];



    long long cur = 0;
    int i;
    for (i = 0 ; i < n * n ; i++) {
        int mask = (a[p[i].fi] & a[p[i].se]);
        if (cur + F[op[mask]] >= k) break;
        cur += F[op[mask]];
    }
    if (i == n * n) {
        cout << -1;
        return 0;
    }
    int mask = (a[p[i].fi] & a[p[i].se]);
    
    for (int j = 0 ; j <  n * n ; j++) {
        int nw = (a[p[j].fi] & a[p[j].se]);
        if ((mask & nw)) continue;
        cur++;
        if (cur == k) {
            cout << p[i].fi << " " << p[i].se << " " << p[j].fi << " " << p[j].se;
            return 0;
        }
    }
        cout << -1;

    return 0;
}