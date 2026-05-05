#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int one_step = solve(n - 1);
    int two_step = solve(n - 2);
    return one_step + two_step;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
