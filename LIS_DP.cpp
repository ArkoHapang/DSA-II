#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int LIS(int i, int p, vector<int>& nums) {
    if (i >= nums.size())
        return 0;

    if (dp[i][p + 1] != -1) return dp[i][p + 1];

    int skip = LIS(i + 1, p, nums);
    int take = 0;
    if (p == -1 || nums[p] < nums[i])
        take = 1 + LIS(i + 1, i, nums);

    return dp[i][p + 1] = max(take, skip);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    memset(dp, -1, sizeof(dp));

    cout << LIS(0, -1, nums);
    return 0;
}

