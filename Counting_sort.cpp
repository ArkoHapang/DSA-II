// https://www.hackerrank.com/challenges/quicksort1/problem?isFullScreen=true
#include<bits/stdc++.h>
using namespace std;
vector<int> countingSort(vector<int> arr) {
    int Max = INT_MIN;
    for(int i : arr){
        Max = max(i, Max);
    }
    vector<int>freq(100);
    for(int i = 0; i<arr.size(); i++){
        freq[arr[i]]++;
    }
    return freq;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<int>ans = countingSort(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}
