#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanford(int V, vector<vector<int>>& edges, int src) {
        vector<int> result(V, 1e8);
        result[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto vec : edges) {
                int u = vec[0];
                int v = vec[1];
                int w = vec[2];
                if (result[u] != 1e8 && result[u] + w < result[v])
                    result[v] = result[u] + w;
            }
        }


        for (auto vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            if (result[u] != 1e8 && result[u] + w < result[v])
                return {-1};
        }

        return result;
    }
};


int main() {
    int V, E, src;
    cin >> V >> E >> src;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    Solution sol;
    vector<int> result = sol.bellmanford(V, edges, src);

    if (result[0] == -1)
        cout << "Negative cycle detected!" << endl;
    else
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " : " << result[i] << endl;

    return 0;
}
