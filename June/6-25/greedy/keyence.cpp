// https://algo-logic.info/greedy/
// https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
// 区間スケジューリング問題・超頻出らしい

#include<bits/stdc++.h>
using namespace std;

// 問題：ロボットアームの長さl,ロボットの座標xとして、共通部分を持たないで置けるロボットの最大個数を求める。
// 方針：終端が小さいものを優先的に採用するgreedy.

int main () {
    int n;
    cin >> n;
    vector<pair<int,int> >co(n);
    for (int i=0; i<n; i++) {
        int x,l;
        cin >> x >> l;
        co.at(i).first = x+l;    // 終端をfirstに入れる。
        co.at(i).second = x-l;
    }

    sort(co.begin(), co.end());  // 終端を優先してsort.


    int ans = 1;
    int t = co.at(0).first;
    for (int i=1; i<n; i++) {
        if (t <= co.at(i).second) {   // 終端が次のロボットの始端と被っていないかチェック
            ans++;
            t = co.at(i).first;
        }
    }

    cout << ans << endl;
}