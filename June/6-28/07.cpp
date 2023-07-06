// https://algo-method.com/tasks/907
// Q7. 箱の内部の箱の個数 (2)
#include <bits/stdc++.h>
using namespace std;

int rec (int v, vector<vector<int> >&child) {
    int ans = 1;
    for (auto c : child.at(v)) {
        ans += rec(c, child);
    }
    return ans;
}

int main () {
    int n;
    cin >> n;

    vector<int>parent;
    parent.push_back(-1);   //先頭は使わないので適当に-1を入れておく

    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        parent.push_back(a);
    }

    vector<vector<int> >child(n);

    for (int i=1; i<n; i++) {
        int p = parent.at(i);
        child.at(p).push_back(i);
    }

    int q;
    cin >> q;

    vector<int>query;
    for (int i=0; i<q; i++) {     //一旦全部の入力を受けてvectorで保持しておく
        int v;
        cin >> v;
        query.push_back(v);
    }

    for (int i=0; i<q; i++) {    //全ての入力を終えてから、まとめて出力
        int v = query.at(i);
        cout << rec(v, child)-1 << endl;
    }
}