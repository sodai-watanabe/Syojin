// https://algo-method.com/tasks/908
// 親が分からない根つき木
// vの兄弟の数を求める。
// 無向グラフと見て、双方隣接リストを作る。頂点vと隣接している頂点nvとして、nvがvの親であるpと異なれば、nvはvの子になる。
// 引数として必要な情報 (対象の頂点v, vの親p, 隣接リストadj, 子頂点リストchild, 親頂点配列)

#include <bits/stdc++.h>
using namespace std;

//vectorの中身を埋めるだけなのでvoid関数に注意
void rec(int v, int p, vector<vector<int> >&adj, vector<vector<int> >&child, vector<int>&parent) {  
    for (auto nv : adj.at(v)) {
        if (nv != p) {         //もしvの隣接頂点nvが、vの親pでなければ、nvはvの子
            child.at(v).push_back(nv);
            parent.at(nv) = v;
            rec(nv, v, adj, child, parent);
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<vector<int> >child(n);
    vector<vector<int> >adj(n);
    

    for (int i=0; i<n-1; i++) { //まずは隣接リストを埋める
        int a, b;
        cin >> a >> b;
        adj.at(a).push_back(b);
        adj.at(b).push_back(a);
    }

    vector<int>parent(n, 1);
    
    rec(0, -1, adj, child, parent);    //上で作ったrec()を実行

    int q;
    cin >> q;

    vector<int>query;

    for (int i=0; i<q; i++) {
        int v;
        cin >> v;
        query.push_back(v);
    }

    for (int i=0; i<q; i++) {
        int p = parent.at(query.at(i));     //対象の点vの親をpとする
        sort(child.at(p).begin(), child.at(p).end());
        for (auto c : child.at(p)) {    //pの子の数はつまりvの兄弟の数(vを含む)
            cout << c << " ";
        }
        cout << endl;
    }
}