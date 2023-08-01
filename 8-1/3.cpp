// https://algo-method.com/tasks/341/editorial
// ナップサック問題
// 教訓：配るdp→未来のことも分かっていることがある。(既に配っていれば先のマスの情報は存在する)ただし、今見ているマスは到達済みである必要があり、未到達の場合はスルーする。
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    vector<int>A(N-1);
    vector<int>B(N-1);
    for (int i=0; i<N-1; i++) {
        cin >> A[i];
    }
    for (int i=0; i<N-1; i++) {
        cin >> B[i];
    }

    vector<vector<int> >dp(N, vector<int>(M,-1));
    dp[0][0] = 0;  // 初期条件

    for (int i=0; i<N-1; i++) {  // dp[i][j]を探索し、その先のマスへ情報を配る。
        for (int j=0; j<M; j++) {
            if(dp[i][j]==-1) continue;  // 未到達の場合はスルー。

            // 一つ先のマス(真下)は、今見ているマスと一つ先のマス自身の大きい方。一つ先が未到達の時は-1なので自動的にdp[i][j]が採用。
            dp[i+1][j]=max(dp[i][j],dp[i+1][j]);  // 注意：真下移動はポイント追加なし(問題設定把握)
            
            // 一つ下で右へA[i]の場合、先のマスは今見ているマスにB[i]を加算したものと先のマスそれ自身の大きい方。先のマスが未到達の場合は上と同様。
            if (j+A[i]<M) {
                dp[i+1][j+A[i]]=max(dp[i][j]+B[i],dp[i+1][j+A[i]]);
            }
        }
    }

    cout << dp[N-1][M-1];
}