// 問題：Nこのボールは重さが違う。総重量Mになる選び方は存在するかを判定せよ
// https://algo-method.com/tasks/337
// 方針：前問と同じ方針に帰着させる。2次元dp配列をもち、1つ下または1つ下でW[i]だけ右の2通り。これはボールiを選ぶ場合と選ばない場合に対応。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    vector<int>W(N);
    // 2次元dp配列は(N+1)*(M+1)
    vector<vector<bool> >dp(N+1, vector<bool>(M+1, false));

    for (int i=0; i<N; i++) {
        cin >> W[i];
    }

    dp[0][0]=true;  // 初期値忘れずに

    for (int i=0; i<N; i++) {  // 範囲注意
        for (int j=0; j<M+1; j++) {
            if (!dp[i][j]) continue;  // 今見てるますがfalseならそもそもスルー

            dp[i+1][j] = true; // 一つ下へ

            if (j+W[i]<M+1) dp[i+1][j+W[i]] = true;  // 一つ下でW[i]だけ右へ
        }
    }

    if (dp[N][M]) cout << "Yes" << endl;
    else cout << "No" << endl;
}