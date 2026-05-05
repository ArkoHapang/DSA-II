#include<bits/stdc++.h>
using namespace std;

int LIS(int i, int p, vector<int>& nums) {
    if (i >= nums.size())
        return 0;

    int skip = LIS(i + 1, p, nums);
    int take = 0;
    if (p == -1 || nums[p] < nums[i])
        take = 1 + LIS(i + 1, i, nums);

    return max(take, skip);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << LIS(0, -1, nums);
    return 0;
}
