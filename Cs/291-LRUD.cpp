// LRUD  8/20, 復習1/14
// 座標で、上下左右を移動するクエリが入力される。すでに訪問済みの座標に再び行く場合は"Yes"。そうでない場合は"No"
// 教訓：制約が大きい時の2次元配列はTEL → 代わりにsetを用いる。
// 教訓：重複判定問題はset
// 教訓：座標の表現　→ 2次元配列 or pair型


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll N;
    string S;
    cin >> N >> S;
    ll x = 0;
    ll y = 0;

    set<pair<ll,ll> >p; // 座標をpair型に持つ
    pair<ll,ll>start = make_pair(x,y);  // 2次元配列を持つとTELなので座標をpair型にしてsetで管理する

    p.insert(start); // 原点スタート。

    for (ll i=0; i<N; i++) {
        // それぞれの文字で座標を更新
        if (S[i]=='U') y++;
        if (S[i]=='D') y--;
        if (S[i]=='R') x++;
        if (S[i]=='L') x--;

        // 現在いる座標をnowに更新。
        pair<ll,ll>now = make_pair(x,y);

        // すでにnowがset内にある場合は訪問済み
        if (p.count(now)) {
            cout << "Yes" << endl;
            return 0;
        }
        p.insert(now);  // nowをsetへ追加
    }

    cout << "No" << endl;
    return 0;
}