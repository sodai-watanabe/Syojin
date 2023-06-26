// https://algo-method.com/tasks/895
// ２分木、
// 長さ0のvectorはpesh_back
// 長さありのvectorは.at()で指定。
// vectorの要素追加周りでいつも詰まっているので、勿体無い


#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int> >child(n);
    vector<int>parent(n, -1);
    

    for (int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        parent.at(b) = a;

        child.at(a).push_back(b);
    }

    int q;
    cin >> q;
    vector<int>query;      //長さ0vectorで宣言

    for (int i=0; i<q; i++) {
        int v;
        cin >> v;
        query.push_back(v);  //長さ0ならpush_back.
    }

    for (int i=0; i<n; i++) {
        sort(child.at(i).begin(), child.at(i).end());
    }

    for (int i=0; i<q; i++) {
        int v = query.at(i);
        int pa_v = parent.at(v);

        for (auto ci : child.at(pa_v)) cout << ci << " ";
        cout << endl;
    }

}