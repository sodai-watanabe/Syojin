// 部分和問題応用
// 二つの箱とN個のボールがありそれぞれW[i]と数字が書かれている。箱にボールを振り分けていき、箱内の数の総和の差が最小になる時の差を求める。
// 教訓：ボールの数iを縦軸、差jを横軸にもつdp配列を用意する。到達しうる差jのマスをtrueに更新していく。
// 2箱の差:大きい方に入れた場合(差は広がる)、小さい方に入れた場合(差は縮まる可能性あり,W[i]が大なら広がるかも)の2パターンを考える。
// https://algo-method.com/tasks/353

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    int INF = 100000; // macx = Wmax*N
    vector<int>W(N);
    for (int i=0; i<N; i++) {
        cin >> W[i];
    }

    // 縦軸iはボールの数、横軸jは二つの箱の総和の差となるdp配列を用意。
    vector<vector<bool> >dp(N+1, vector<bool>(INF,false));

    dp[0][0]=true; //初期条件

    for (int i=0; i<N; i++) {
        for (int j=0; j<INF; j++) {
            if (!dp[i][j]) continue;

            if (j+W[i]<INF) dp[i+1][j+W[i]]=true;  // 総和が大きい方の箱に入れた場合。j+W[i]>jなので差は広がる。

            dp[i+1][abs(j-W[i])]=true;  // 総和が小さい方に入れた場合。j-W[i]<jなので差は縮まる。
        }
    }

    // ボールを全て入れた時(i=N)、差(j)が最小のものを出力
    for (int j=0; j<INF; j++) {
        if (dp[N][j]) {
            cout << j;
            return 0;
        }
    }
}