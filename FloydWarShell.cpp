#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist){

    int n = dist.size();

    for(int via = 0; via < n; via++){

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                // Avoid infinity overflow
                if(dist[i][via] != 1e8 &&
                   dist[via][j] != 1e8){

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][via] + dist[via][j]
                    );
                }
            }
        }
    }
}

int main(){

    int n;

    cout<<"Enter number of nodes: ";

    cin>>n;

    vector<vector<int>>dist(n, vector<int>(n));

    cout<<"Enter adjacency matrix:"<<endl;
    cout<<"Use 100000000 for INF"<<endl;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cin>>dist[i][j];
        }
    }

    floydWarshall(dist);

    cout<<"Shortest Distance Matrix:"<<endl;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(dist[i][j] == 1e8)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }

        cout<<endl;
    }
}
