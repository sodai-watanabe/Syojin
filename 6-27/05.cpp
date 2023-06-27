// https://algo-method.com/tasks/905
// 帰りがけ順
#include <bits/stdc++.h>
using namespace std;

void rec (int v, vector<vector<int> >&child) {
    for (auto c : child.at(v)) {
        rec (c,child);
    }
    cout << v << " ";
}

int main () {
    int n;
    cin >> n;
    vector<vector<int> >child(n);
    vector<int>parent;
    parent.push_back(-1);

    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        parent.push_back(a);
    }

    for (int i=1; i<n; i++) {
        int p = parent.at(i);
        child.at(p).push_back(i);
    }

    rec(0, child);
}

