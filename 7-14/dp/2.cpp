// https://algo-method.com/tasks/303
// 直線マスの移動。1マスか2マスどちらかで、最小コストを出力。
// 教訓：再帰でdp書くならメモ化しないとTEL.
// この問題の場合は再帰でなく、forで数列をA0から順に出すこともできる(それの方がシンプル)
#include <bits/stdc++.h>
using namespace std;

int dp (int N, vector<int>&A, vector<int>&T) {
    if (T[N]!=-1) return T[N];  // memo

    if (N == 0) return T[N]=0;  // 初期条件
    if (N == 1) return T[N]=A[1];
    
    return T[N] = min(dp(N-1,A,T)+A[N],dp(N-2,A,T)+2*A[N]);  // 許される2パターンのうち、コストが小さい方
}

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    vector<int>T(N,-1);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    cout << dp(N-1,A,T) << endl;
}