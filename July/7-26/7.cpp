// https://algo-method.com/tasks/335/editorial
// 2次元dp 最小化問題
// 教訓：最小化問題の場合、取りうる最大値を初期値に設定する必要がある。
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<vector<int> >A(N, vector<int>(N));
    vector<vector<int> >dp(N, vector<int>(N,1000000));   // N*Nが取りうる最大値。余裕を持った大きさを持たせる。

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }

    dp[0][N-1]= A[0][N-1];

    for (int i=0; i<N; i++) {
        for (int j=N-1; 0<=j; j--) {  // 今回は右上スタート、左下ゴールなので 
            if (i-1 >= 0)  // 上からくる場合
                dp[i][j]=min(dp[i][j],dp[i-1][j]+A[i][j]);

            if (j+1 < N)  // 右から来る場合
                dp[i][j]=min(dp[i][j],dp[i][j+1]+A[i][j]);    
        }
    }

    cout << dp[N-1][0] << endl;
}