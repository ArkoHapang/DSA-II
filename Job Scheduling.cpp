#include <bits/stdc++.h>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}
void jobScheduling(vector<Job>& jobs) {

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;

    for (auto job : jobs) {
        for (int t = job.deadline; t > 0; t--) {

            if (slot[t] == -1) {
                slot[t] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {

    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    jobScheduling(jobs);

    return 0;
}
