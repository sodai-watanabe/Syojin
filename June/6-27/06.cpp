// https://algo-method.com/tasks/909
// 箱の内部の箱の個数 (1)

#include <bits/stdc++.h>
using namespace std;

int rec (int v, vector<vector<int> >&child) {
    int ans = 1;        //自分(v)の分の1を数える
    for (auto c : child.at(v)) {
        ans += rec(c, child);    //自分(v)の子供のそれぞれの子孫の数
    }
    return ans;   //自分以下の子孫の数を返す。(自分を含める)
}

int main () {
    int n;
    cin >> n;
    vector<int>parent;
    parent.push_back(-1);

    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        parent.push_back(a);
    }

    vector<vector<int> >child(n);

    for (int i=1; i<n; i++) {
        int p = parent.at(i);
        child.at(p).push_back(i);    //child.at(p)は長さが無いのでpush_backを使うこと
    }

    int v;
    cin >> v;

    int ans = rec(v, child);
    cout << ans-1;          // v自身の1を最後に引く
}

