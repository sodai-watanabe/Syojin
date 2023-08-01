// https://algo-method.com/tasks/427
//  部分和問題 (再帰-1)
// 複数の整数を用いてjを作るとき、次の2パターンがある。　①A[i-1]を使ってjを作る②A[i-1]を使わずにjを作る
// fragを用意し、上の2パターンを満たせばtrueを入れる。
// i==0の時、j==0であればtrueを返す。

#include <bits/stdc++.h>
using namespace std;

bool func (int i, int j, vector<int>&A) {
    if (i==0) return j==0;

    bool frag = false;
    if (j-A[i-1]>=0 && func(i-1, j-A[i-1], A)) frag = true;  // A[i-1]を使ってjを作れる
    if (func(i-1,j,A)) frag = true;                          // A[i-1]を使わずにjを作れる

    return frag; 
}

int main () {   
    int N, X;
    cin >> N >> X;

    vector<int>A(N);

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    string ans = func(N, X, A) ? "Yes" : "No" ;
    cout << ans << endl;
}