// don't be cycled　要復習9/11
// 問題：グラフが閉路を持たないために消すべき辺の最小数を求める。
// 方針：まず、閉路を持たない構造を木構造という。木である(閉路を持たない)条件は変数がN-1本。この性質を使う。
// 教訓：一つの連結成分が木構造(閉路を持たない)である条件 → 頂点数Nの時、辺の数はN-1本
// 教訓：S個の連結成分において、閉路を持たない条件 → 頂点数Nの時、N-S
// 教訓：連結成分の数　→ dfsで探索。既にみられている頂点はスルー。全ての頂点でdfsを試す。スルーされなかった頂点数が連結成分の数。

#include <bits/stdc++.h>
using namespace std;
int cycle;

void dfs (int v, vector<vector<int> >&child, vector<bool>&seen) {
    if (seen[v]==true) return;
    // cout << v;
    seen[v]=true;

    for (auto c : child[v]) {
        dfs(c, child, seen);
    }
}

int main () {
    int N, M;
    cin >> N >> M;

    vector<vector<int> >child(N+1);

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;

        child[a].push_back(b);
        child[b].push_back(a);
    }

    vector<bool>seen(N+1,false);
    int s=0;

    for (int i=1; i<=N; i++) {
        if (!seen[i]) {
            s++;
            dfs(i,child,seen);
        }
    }

    cout << M-N+s << endl;
}