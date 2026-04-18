#include<bits/stdc++.h>
using namespace std;

void Counting(vector<int>&arr){
    int Max = INT_MIN;

    for(int i : arr){
        Max = max(i, Max);
    }

    vector<int>freqq(Max+1);
    vector<int>ans(arr.size());

    for(int i = 0; i<arr.size(); i++){
        freqq[arr[i]]++;
    }

    for(int i = 1; i <= Max; i++){
        freqq[i] += freqq[i-1];
    }

    for(int i = arr.size()-1; i >= 0; i--){
        ans[freqq[arr[i]]-1] = arr[i];
        freqq[arr[i]]--;
    }

    for(auto i : ans){
        cout<<i<<" ";
    }
}

int main(){
    int n; cin>>n;
    vector<int>arr;
    for(int i = 0; i<n; i++){
        int x; cin>>x; arr.push_back(x);
    }
    Counting(arr);
}
