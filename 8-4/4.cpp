// ナップサック問題
// 重さW[i],価値V[i]のボールを箱の中に入れる。重さMを超えないように入れたときの価値の最大値を求める。
// https://algo-method.com/tasks/342
// 方針：縦N横Mの2次元dp配列。左上からスタート、ボールを取らない場合は下へ1つ移動、撮る場合は下へ一つと右へW[i]個移動することに対応。dp配列をiマスずつ探索して、上のパターンを配っていく。(配るdp)

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    vector<int>W(N);
    vector<int>V(N);

    for (int i=0; i<N; i++) {
        cin >> W[i];
    }
    for (int i=0; i<N; i++) {
        cin >> V[i];
    }

    vector<vector<int> >dp(N+1,vector<int>(M+1,-1));

    dp[0][0]=0;  //　初期条件忘れがち

    for (int i=0; i<N; i++) {
        for (int j=0; j<=M; j++) {
            if (dp[i][j]==-1) continue; // 今見てるマスが未探索の場合はスルー

            dp[i+1][j]=max(dp[i][j],dp[i+1][j]); // 一つ下。

            if (j+W[i]<=M) {  // 一つ下かつW[i]だけ右へ。配列外が起きないように
                dp[i+1][j+W[i]]=max(dp[i+1][j+W[i]],dp[i][j]+V[i]);
            }
        }
    }

    sort(dp[N].begin(), dp[N].end());

    cout << dp[N][M];
}