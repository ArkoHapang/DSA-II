#include<bits/stdc++.h>
using namespace std;

int dp[100];

int solve(int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1) return dp[n];

    int one_step = solve(n - 1);
    int two_step = solve(n - 2);
    return dp[n] = one_step + two_step;
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    return 0;
}
