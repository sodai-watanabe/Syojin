// マス移動応用
// https://algo-method.com/tasks/306

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N,M;
    cin >> N >> M;
    vector<int>A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    vector<int>dp(N,100000);  // 最小値問題はINFで初期化
    dp[0]=0;

    for (int i=1; i<N; i++) {
        for (int j=i-M; j<i; j++) {
            if (0<=j) {
                dp[i] = min(dp[j]+(i-j)*A[i],dp[i]);
            }
        }     
    }
    cout << dp[N-1];
}