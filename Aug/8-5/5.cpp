// 部分和問題応用
// N個のボールに数字が書いてある。できるだけ少ないボールで数字の合計をMにした時のボールの個数を求めよ
// https://algo-method.com/tasks/350
// 教訓：最小値問題→①初期値INFを設定　②dp配列内ではminで判定。③配るdpの場合は、先のマスが到達済みの可能性もあるので先のマスも条件に入れる。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    vector<int>W(N);

    for (int i=0; i<N; i++) {
        cin >> W[i];
    }

    int INF = 110;  // 初期値INF

    vector<vector<int> >dp(N+1,vector<int>(M+1,INF)); // INFで初期化
    dp[0][0]=0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (dp[i][j]==-1) continue;

            dp[i+1][j]=min(dp[i][j],dp[i+1][j]); // 下へ一つ。ボールを選ばない時に対応。すでにdp[i+1][j]が到達済みの可能性もあるのでminで比較する必要がある。

            if (j+W[i]<=M) dp[i+1][j+W[i]]= min(dp[i+1][j+W[i]], dp[i][j] + 1); // ボールが選ばれる場合。上と基本的には同じ。
        }
    }

    int ans = 110;

    for (int i=0; i<=N; i++) {
        if (dp[i][M]>0) ans = min(ans,dp[i][M]);  // 右端の列で値が入っているものの中で一番小さいもの。
    }

    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }

}