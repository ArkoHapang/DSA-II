#include<bits/stdc++.h>
using namespace std;

int LCS(int i, int j, string& s1, string& s2) {
    if (i == s1.length() || j == s2.length())
        return 0;

    if (s1[i] == s2[j])
        return 1 + LCS(i + 1, j + 1, s1, s2);
    else {
        int option1 = LCS(i + 1, j, s1, s2);
        int option2 = LCS(i, j + 1, s1, s2);
        return max(option1, option2);
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << LCS(0, 0, s1, s2);
    return 0;
}
