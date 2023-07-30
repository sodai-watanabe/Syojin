// https://algo-method.com/tasks/336
// 配るdp
// 教訓：dp[i][j]を順にみて、その状態に応じて直後のdpに結果を配る。
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    vector<int>A(N-1);
    for (int i=0; i<N-1; i++) {
        cin >> A[i];
    }

    vector<vector<bool> >dp(N, vector<bool>(M,false));  // point:2択しかないならbool型。

    dp[0][0]=true;  // 詰まった：初期状態を忘れずに

    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M; j++) {
           if (!dp[i][j]) continue;

           dp[i+1][j] = true;

           if (j+A[i]<M) dp[i+1][j+A[i]]=true;  // 詰まった：直後(未来)の状態の条件に注意。j+A[i]<Mは右側が配列内にあるか。
        }
    }

    int ans = 0;

    for (int i=0; i<M; i++) {  // 集計
        if (dp[N-1][i]) ans++;
    }

    cout << ans;
}