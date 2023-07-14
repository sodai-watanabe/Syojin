// https://algo-method.com/tasks/302
// 後ろから計算するdpを作ったけど、この場合はシンプルに前から数列を順番に計算しても良い。

#include <bits/stdc++.h>
using namespace std;

int dp (int N, int X, int Y, vector<int>&A) {
    if (A[N]!=-1) return A[N];  // 最初この行なしでやったらTELだったので、メモ化するようにした。

    if (N == 0) return A[N]=X;
    if (N == 1) return A[N]=Y;
    
    return A[N] = (dp(N-1,X,Y,A)+dp(N-2,X,Y,A))%100;
}

int main () {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int>A(N,-1);   // メモ化のために-1で初期化

    int ans = dp(N-1,X,Y,A);
    cout << ans << endl;
}