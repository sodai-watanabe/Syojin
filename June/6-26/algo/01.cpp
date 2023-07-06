// https://algo-method.com/tasks/894/editorial
// 二分木
// 連結性が与えられたら、いつも通りの隣接リストで持つ。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int> >child(n);
    vector<int>parent;
    // 0の親はいないので、index=0には0を入れておく
    parent.push_back(0);

    // そのindexの親の番号が順番に与えられる。実質親子関係が与えられている。
    for (int i=0; i<n-1; i++) {
        int p;
        cin >> p;
        child.at(p).push_back(i+1);  //空vectorはpush_back,長さありvectorは.at()で代入
        parent.push_back(p);
    }

    int q;
    cin >> q;

    vector<int>query;

    for (int i=0; i<q; i++) {
        int v;
        cin >> v;
        query.push_back(v);
    }

    for (int i=0; i<q; i++) {
      int v = query.at(i);
      int pa_v = parent.at(v);
      for (auto ci : child.at(pa_v)) {
        cout << ci << " ";
      }
      cout << endl;
    }
}