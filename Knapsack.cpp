#include <bits/stdc++.h>

using namespace std;

struct Item {
    // Fill it yourself
};

bool compare(Item a, Item b) {
    // TODO: Sort in descending order of ratio
    return ____________________;
}

void fractionalKnapsack(vector<Item>& items, double capacity) {

    // Step 1: Compute ratio
    for (auto &item : items) {
        item.ratio = item.profit / item.weight;
    }

    // Step 2: Sort items
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;

    cout << "Selected Items:\n";

    // Step 3: Take items greedily
    for (auto item : items) {

        if (capacity >= item.weight) {

            // Take full item
            capacity -= item.weight;
            totalProfit += item.profit;

            cout << "Item " << item.id << " (Full)\n";
        }
        else {
            // Take fractional part
            totalProfit += capacity * item.ratio;

            cout << "Item " << item.id
                 << " (Fractional, Weight taken = "
                 << capacity << ")\n";

            capacity = 0;
            break;   // Knapsack is full
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
}

int main() {

    vector<Item> items = {
        {1, 10, 60, 0},
        {2, 20, 100, 0},
        {3, 30, 120, 0}
    };

    double capacity = 50.0;

    fractionalKnapsack(items, capacity);

    return 0;
}
