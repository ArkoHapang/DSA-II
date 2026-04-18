#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    double mid = (m + 1) / 2.0;

    vector<int> order(m);
    iota(order.begin(), order.end(), 1);

    sort(order.begin(), order.end(), [&](int a, int b) {
        double da = abs(a - mid);
        double db = abs(b - mid);
        if (da != db) return da < db;
        return a < b;
    });

    for (int i = 1; i <= n; i++) {
        cout << order[(i - 1) % m] << "\n";
    }

    return 0;
}
