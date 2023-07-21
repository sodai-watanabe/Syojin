#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<vector<int> >dp(N, vector<int>(N));

    dp[0][0]=1;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {

            if (i-1 >= 0) {
                dp[i][j]+=dp[i-1][j];  // 上から来る場合
            }
            if (j-1 >= 0) {
                dp[i][j]+=dp[i][j-1];  // 左から来る場合
            }

            // if (i==0 && j==0) continue;

            // if (j==0) {
            //     dp[i][j]=dp[i-1][j];
            // } else if (i==0) {
            //     dp[i][j]=dp[i][j-1];
            // } else {
            //     dp[i][j]=dp[i-1][j]+dp[i][j-1];
            // }
        }
    }

    cout << dp[N-1][N-1];
}