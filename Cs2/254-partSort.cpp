// special sort 要復習9/23、12/24
// 問題：要素数Nの配列Aがある。A[i]とA[i+K]を入れ替える操作を好きなだけ行うことで、Aを昇順に並べることが可能かどうかを判定せよ。
// 教訓：配列A内の特定要素のみのK個の部分配列を扱う → K回loopで使い捨て配列bを用意する。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    // 元配列Aの要素数N,K
    ll N,K;
    cin >> N >> K;
    vector<ll>A(N+1);
    for (ll i=1; i<=N; i++) {
        cin >> A[i];
    }

    // AはK個の部分配列を持つ。それぞれの部分配列を作る。
    // 部分配列を作って元配列に戻す。
    // K回繰り返すと操作を十分に行った後のAが出来上がる。
    for (int i=1; i<=K; i++) {
        // 部分配列を作るための、使い捨て配列。
        vector<ll>b;

        // indexはKずつ大きくなる。部分配列の要素はA内にKおきにある。
        for (int r=i; r<=N; r+=K) {
            b.push_back(A[r]);
        }
        // 部分配列をsort
        sort(b.begin(),b.end());

        // sortした部分配列を元配列Aに反映する。元の位置に戻す。
        int r = i;
        for (auto j : b) {
            A[r]=j;
            r+=K;
        }
    }

    // 元配列をsortして、出来上がった新配列Aと比較する。
    vector<ll>copy=A;
    sort(copy.begin(),copy.end());

    if (copy==A) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}