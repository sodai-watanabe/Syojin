// https://algo-method.com/tasks/333
// 2次元dp
// 一つ前とほぼなじ
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<string>S(N);
    for (int i=0; i<N; i++) {
        cin >> S[i];
    }

    vector<vector<int> >dp(N, vector<int>(N));  // ここでdpの第二引数を設定せずにミスをしていたので注意
    dp[0][0] = 1;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i-1>=0 && S[i][j]=='.') {
                dp[i][j] += dp[i-1][j];
            }
            if (j-1>=0 && S[i][j]=='.') {
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    cout << dp[N-1][N-1];
}