#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

int knapsack(int idx, int capacity, vector<Item>& items) {
    if (idx >= items.size())
        return 0;

    int skip = knapsack(idx + 1, capacity, items);

    int take = 0;
    if (capacity >= items[idx].weight)
        take = items[idx].value + knapsack(idx + 1, capacity - items[idx].weight, items);

    return max(skip, take);
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].weight >> items[i].value;

    cout << knapsack(0, capacity, items);
    return 0;
}
