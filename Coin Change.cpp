#include<bits/stdc++.h>
using namespace std;

int coin[1001];

int coinchange(int i, int t, int n) {
    if (t == 0) return 1;
    if (t < 0 || i >= n) return 0;

    int skip = coinchange(i + 1, t, n);
    int take = 0;
    if (t >= coin[i])
        take = coinchange(i, t - coin[i], n);

    return take + skip;

int main() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    cout << coinchange(0, t, n);
    return 0;
}
