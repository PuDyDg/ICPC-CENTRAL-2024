#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 105;
int n, W, H;
int w[N], c[N];
int dp[2][101005];
signed main() {

    cin >> n >> W >> H;

    for (int i = 1 ; i <= n ; i++) {
        cin >> w[i] >> c[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int hand = 1 ; hand >= 0 ; hand--)
            for (int j = 100000 ; j >= 0 ; j--) {
                if (hand == 0 && w[i] <= H) dp[1][j + c[i]] = min(dp[1][j + c[i]], dp[hand][j]);
                dp[hand][j + c[i]] = min(dp[hand][j+c[i]], dp[hand][j] + w[i]);
            }   
    }

    for (int i = 101000 ; i >= 0 ; i--)
        if (dp[0][i] <= W || dp[1][i] <= W) {
            cout << i;
            return 0;
        }
}
