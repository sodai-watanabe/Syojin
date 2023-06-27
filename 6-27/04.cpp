// recursion
// 行き掛け順
#include <bits/stdc++.h>
using namespace std;

void rec (int v, vector<vector<int> >&child) {
    cout << v << " ";

    for (auto c : child.at(v)) {
        rec(c, child);
    }
}

int main () {
    int n;
    cin >> n;

    vector<vector<int> >child(n);
    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        child.at(a).push_back(i);
    }

    rec(0, child);
}