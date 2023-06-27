// https://algo-method.com/tasks/904
// 葉の個数を出力する
// 葉とは子を持たない頂点。
// vectorの要素追加に注意して実装できた。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int>parent;
    parent.push_back(0);

    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        parent.push_back(p);
    }

    vector<vector<int> >child(n);

    for (int i=1; i<n; i++) {
        int p = parent.at(i);
        child.at(p).push_back(i);
    }

    int ans = 0;

    for (int i=1; i<n; i++) {
        if (child.at(i).size() == 0) ans++; 
    }

    cout << ans << endl;
}
