#include<bits/stdc++.h>
using namespace std;

int coin[1001];
int dp[1001][1001];

int coinchange(int i, int t, int n) {
    if (t == 0) return 1;
    if (t < 0 || i >= n) return 0;

    if (dp[i][t] != -1) return dp[i][t];

    int skip = coinchange(i + 1, t, n);
    int take = 0;
    if (t >= coin[i])
        take = coinchange(i, t - coin[i], n);

    return dp[i][t] = take + skip;
}

int main() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    memset(dp, -1, sizeof(dp));

    cout << coinchange(0, t, n);
    return 0;
}
