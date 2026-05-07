#include<bits/stdc++.h>
using namespace std;

int price[100];

int rc(int i, int n) {
    if (n == 0 || i > n) return 0;

    int skip = rc(i + 1, n);
    int take = price[i] + rc(i, n - 1);

    return max(take, skip);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> price[i];

    cout << rc(1, n);
    return 0;
}

