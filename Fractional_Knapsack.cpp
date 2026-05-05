#include <bits/stdc++.h>
using namespace std;
struct Item {
    int id;
    double weight;
    double profit;
    double ratio; // Value per unit weight
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
void fractionalKnapsack(vector<Item>& items, double capacity) {
    for (auto &item : items) {
        item.ratio = item.profit / item.weight;
    }
    sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
     cout << "Selected Items:\n";
    for (auto item : items) {
        if (capacity <= 0) break; 
         if (capacity >= item.weight) {
            capacity -= item.weight;
            totalProfit += item.profit;
            cout << "Item " << item.id << " (Full)\n";
        }
        else {
            totalProfit += capacity * item.ratio;
             cout << "Item " << item.id 
                 << " (Fractional, Weight taken = " 
                 << capacity << ")\n";

            capacity = 0; 
            break;    
        }
    }
     cout << "Total Profit: " << totalProfit << endl;
}
int main() {
    vector<Item> items = {
        {1, 10.0, 60.0, 0.0},
        {2, 20.0, 100.0, 0.0},
        {3, 30.0, 120.0, 0.0}
    };
    double capacity = 50.0;
    fractionalKnapsack(items, capacity);
    return 0;
}
