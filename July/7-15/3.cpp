// https://algo-method.com/tasks/41
// dpらしい問題。3つの仕事をN日間やるときの報酬の最大化
// dp2次元配列を用意。直前の情報を使って条件をかく。i日目であり得る全てのパターンをdp配列に格納。
// 配列の最大値は*max_element(A.begin(),A.end())で得る。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<vector<int> >A(N, vector<int>(3));
    for (int i=0; i<N; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    vector<vector<int> >dp(N,vector<int>(3));
    dp[0][0]=A[0][0];  // 初期値を設定。
    dp[0][1]=A[0][1];
    dp[0][2]=A[0][2];

    for (int i=1; i<N; i++) {
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+A[i][2];  // i日目では仕事1,2,3の3パターンがありうる。3パターンについて書く。
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+A[i][0];  // 直前の日にち時点での最大報酬を使って条件を書く
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+A[i][1];  // 条件は、直前の日にちでやった仕事以外のうち、報酬が最大のものを選ぶ。
    }

    int ans = *max_element(dp[N-1].begin(),dp[N-1].end());   // 配列の最大値*max_element()で得る。
    cout << ans;
}