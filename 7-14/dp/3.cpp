// https://algo-method.com/tasks/304
// 階段の登り方

#include <bits/stdc++.h>
using namespace std;

int dp (int i, vector<int>&A) {
    if (A[i]!=-1) return A[i];

    if (i==0) return A[i]=0;
    if (i==1) return A[i]=1;
    if (i==2) return A[i]=2;               //dp(i-2,A)を呼ぶのでi==2まで初期値が必要

    return A[i] = dp(i-1,A) + dp(i-2,A);   // ちゃんと自分自身を呼び出していることを確認
}

int main () {
    int N;
    cin >> N;

    vector<int>A(N+1,-1);

    cout << dp(N,A);
}