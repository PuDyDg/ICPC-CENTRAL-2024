#include "bits/stdc++.h"
#define pii pair <int, int>
#define fi first
#define se second

using namespace std;

const int inf = 1e9;
const int N = 10005;
int n, nA, nB, nC;
int s, t;
bool wanna[3][N], used[50];
pii pre[50];
int inp[50], out[50];
vector <pii> ad[50], rev[50];

void add(int i, int j, int val) {
    ad[i].push_back(pii(j, val));
    ad[j].push_back(pii(i, 0));
    rev[i].push_back(pii(j, ad[j].size()-1));
    rev[j].push_back(pii(i, ad[i].size()-1));
 
}
 

void read() {

    memset(wanna, 0, sizeof(wanna));
    for (int i = 0 ; i <= 30 ; i++) {
        ad[i].clear();
        rev[i].clear();
    }

    cin >> n >> nA >> nB >> nC; 
    for (int i = 0 ; i < 3 ; i++) {
        int m;
        cin >> m;
        for (int j = 1 ; j <= m ; j++) {
            int worker;
            cin >> worker;
            wanna[i][worker] = 1;
        }
    } 
}

void build() {

    int id = 0;
    for (int i = 1 ; i < 8 ; i++) {
        inp[i] = ++id;
        out[i] = ++id;
    }
    s = 0;
    t = ++id;

    for (int mask = 1 ; mask < 8 ; mask++) {

        int F = 0, only = 0;
        for (int i = 1 ; i <= n ; i++) {

            int nwmask = 0;
            for (int j = 0 ; j < 3 ; j++)
                nwmask += wanna[j][i] * (1 << j);

            if (nwmask == mask) only++;
            if ((nwmask & mask) == mask) F++;
        }

        add(inp[mask], out[mask], F);
        add(out[mask], t, only);
    }


    add(s, inp[1], nA);
    add(s, inp[2], nB);
    add(s, inp[4], nC);
    
    add(out[1], inp[3], inf);
    add(out[2], inp[3], inf);

    add(out[1], inp[5], inf);
    add(out[4], inp[5], inf);

    add(out[2], inp[6], inf);
    add(out[4], inp[6], inf);

    add(out[3], inp[7], inf);
    add(out[5], inp[7], inf);
    add(out[6], inp[7], inf);
    
}


bool find_path() {
 
    memset(used, 0, sizeof(used));
    used[s] = 1;
    queue <int> q;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0 ; i < ad[u].size() ; i++) {
            int v = ad[u][i].fi;
            int w = ad[u][i].se;
            if (used[v] || w <= 0) continue;
            q.push(v);
            pre[v] = pii(u, i);
            used[v] = 1;
        }
    }
    return used[t];
}
void solve() {

    int res = 0;
    while(find_path()) {
        int cur = t;
        while(cur != s) {
            pii p = pre[cur];
            ad[p.fi][p.se].se--;
            pii rp = rev[p.fi][p.se];
            ad[rp.fi][rp.se].se++;
            cur = p.fi;
        }
        res++;
    }
    cout << res << "\n";
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while(test--) {

        read();
        build();
        solve();

    }
}