// 部分和問題応用
// カードがN枚あり、それぞれ整数が書かれている。Aで割ったあまりがBとなる選び方が存在するかを判定する。
// https://algo-method.com/tasks/352
// 教訓：(N+1)*(N*X)のdp配列(今までのやり方)→計算量超過
// 2次元dp配列で、横を「余り」にする→(N+1)*(A)で十分高速。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int>X(N);
    for (int i=0; i<N; i++) {
        cin >> X[i];
    }

    vector<vector<bool> >dp(N+1,vector<bool>(A+1, false));

    dp[0][0]=true;

    for (int i=0; i<N; i++) {
        for (int j=0; j<A; j++) {
            if (!dp[i][j]) continue;  // 未到達ならスルー

            dp[i+1][j]=true; // 一つ下をtrueに。ボールが選ばれなかった場合に対応

            dp[i+1][(j+X[i])%A]=true;  // 一つ下でボールの数字の合計をAで割ったあまりだけ右のマスをtrueに。ボールが選ばれた時に対応。
        }
    }

    if (dp[N][B]) cout << "Yes";  // j=Bのマスは余りがBに対応。tureの時は条件を満たすものが存在。
    else cout << "No";
}