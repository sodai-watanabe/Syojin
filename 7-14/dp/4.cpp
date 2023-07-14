// タイルの敷き詰め方(長さ1,2,3)
// https://algo-method.com/tasks/305
// 基本、階段と同じ

#include <bits/stdc++.h>
using namespace std;

int dp (int i, vector<int>&A) {
    if (A[i]!=-1) return A[i];

    if (i==0) return A[i]=1;
    if (i==1) return A[i]=2;
    if (i==2) return A[i]=4;

    return A[i] = dp(i-1,A)+dp(i-2,A)+dp(i-3,A);
}

int main () {
    int N;
    cin >> N;

    vector<int>A(N,-1);

    cout << dp(N-1,A);
}