// https://algo-method.com/tasks/423
// メモ化再帰、フィボナッチ数列
// メモ用の配列を用意し、funcは既にメモされていればメモされているものを返し、まだメモがなければメモしたものを返す。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // long long を簡略化して使えるように

ll func (int n, vector<ll>&N) {
    if (n==0 || n==1) return N[n]=n;   // f0,f1は定義から。
    if (N[n]!=-1) return N[n];         // 既にメモ済みであれば、メモされているものをそのまま返す。

    N[n] = func(n-1,N)+func(n-2,N);    // 上以外の場合、fnを定義通り計算しメモする。

    return N[n];   // メモしたものを返す
}

int main () {
    int n;
    cin >> n;
    vector<ll>N(n+1, -1);

    cout << func(n,N) << endl;
}