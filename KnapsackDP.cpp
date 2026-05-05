#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

int dp[100][100];

int knapsack(int idx, int capacity, vector<Item>& items) {
    if (idx >= items.size())
        return 0;

    if (dp[idx][capacity] != -1) return dp[idx][capacity];

    int skip = knapsack(idx + 1, capacity, items);

    int take = 0;
    if (capacity >= items[idx].weight)
        take = items[idx].value + knapsack(idx + 1, capacity - items[idx].weight, items);

    return dp[idx][capacity] = max(skip, take);
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].weight >> items[i].value;

    memset(dp, -1, sizeof(dp));

    cout << knapsack(0, capacity, items);
    return 0;
}
