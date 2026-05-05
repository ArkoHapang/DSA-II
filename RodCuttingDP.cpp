#include<bits/stdc++.h>
using namespace std;

int price[100];
int dp[100][100];

int rc(int i, int n) {
    if (n == 0 || i > n) return 0;

    if (dp[i][n] != -1) return dp[i][n];

    int skip = rc(i + 1, n);
    int take = price[i] + rc(i, n - 1);

    return dp[i][n] = max(take, skip);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> price[i];

    memset(dp, -1, sizeof(dp));

    cout << rc(1, n);
    return 0;
}
