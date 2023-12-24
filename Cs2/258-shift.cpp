// shift 要復習　9/21,12/24→ok
// 文字列のshift
// 問題：文字列Sに対して、query1はx回shift、query2でその時点のSのx番目の文字を出力。
// 入力:N Q
//     S
//     1 x
//     2 x   .......
// 教訓：rotate関数はO(N)くらいかかってしまう。
// 教訓：rotateする代わりに、操作ごとにshiftの回数を累計しておく。shift累計からSのスタートを決めて、そこからx番目の文字を見るといい。
// 教訓：文字列のshift → 一旦範囲外参照を考えずにshift後のSのスタートを出し、最後にまとめて%Nとすると良い。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    // shift方向が都合が悪かったので反転させた。
    reverse(S.begin(),S.end());

    // shift回数の累積。
    ll rot = 0;

    // Q回queryを受け取る。
    for (int i=0; i<Q; i++) {
        int q,x;
        cin >> q >> x;

        // q1の場合、rotを加算。
        if (q==1) {
            rot+=x;
        }
        
        // q2の場合、shift後のSのx番目の文字を出力。
        if (q==2) {
            // 反転してあるので、Sのx番目なら反転SのN-x番目。
            // スタートをshiftの回数だけずらす。
            // 一旦範囲外参照を考えずに、スタート(rot)からN-x番目のindex(rot+N-x)として、最後に範囲外を考えてNの余りとする。
            cout << S[(N-x+rot)%N] <<endl;
        }
    }
}