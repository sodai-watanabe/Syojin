// https://algo-method.com/tasks/334
// ２次元dp

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<vector<int> >A(N, vector<int>(N));
    vector<vector<int> >dp(N, vector<int>(N));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }

    dp[0][0]= A[0][0];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            // if (i==0 && j==0) continue;

            // if (i==0) {
            //     dp[i][j]=dp[i][j-1] + A[i][j];
            //     continue;
            // } 
            // if (j==0) {
            //     dp[i][j]=dp[i-1][j] + A[i][j];
            //     continue;
            // }
            // dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + A[i][j];

            if (i-1 >= 0)   // 上からくる場合
                dp[i][j]=max(dp[i][j],dp[i-1][j]+A[i][j]);

            if (i-1 >= 0)   // 左から来る場合
                dp[i][j]=max(dp[i][j],dp[i][j-1]+A[i][j]);    // 上から来た場合よりも大きければこれを採用
        }
    }

    cout << dp[N-1][N-1] << endl;
}