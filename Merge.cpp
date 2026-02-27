#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = A[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            k++, i++;
        }
        else
        {
            A[k] = R[j];
            k++, j++;
        }
    }
    while(j < n2)
    {
        A[k] = R[j];
        k++, j++;
    }
    while(i < n1)
    {
        A[k] = L[i];
        k++, i++;
    }
}

void merge_sort(int A[], int left, int right)
{
    if(left >= right) return;
    int mid = (left + right)/2;
    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);
    merge(A, left, mid, right);
}

int main()
{
    int A[] = {1,5,8,6,7,4,2,3};
    merge_sort(A, 0, 7);
    cout << "Merged: ";
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    return 0;
}
