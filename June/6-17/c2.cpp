#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int>a(3*n);
    for (int i=0; i<3*n; i++) {
        cin >> a.at(i);
    }

    vector<vector<int> >b(n+1);
    for (int i=0; i<3*n; i++) {
        b.at(a.at(i)).push_back(i+1);
    }

    vector<int> ans(n);
    for (int i=1; i<=n; i++) {
        ans.push_back(i);
    }

    sort(ans.begin(), ans.end(), [&](int x, int y) {
        return b.at(x).at(1) < b.at(y).at(1);
    });

    for (auto a : ans) {
        cout << a << ' ';
    }



}