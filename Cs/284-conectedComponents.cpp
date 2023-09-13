// 連結成分の個数を求める　典型
// 教訓：dfs → seenの更新は最初にやる。次頂点に配る時はしない。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N,M;

void dfs (int v, vector<vector<int> >&child, vector<bool>&seen) {
    if (seen[v]) return;

    seen[v] = true;              // seenの更新は最初にやる。

    for (auto nv : child[v]) {
        if (!seen[nv]) {
            dfs(nv,child,seen);  // dfsにnvを渡す
            // seen[nv] = true;  //　これは間違い
        }
    }
}

int main () {
    cin >> N >> M;
    vector<vector<int> >child(N);
    for (int i=0; i<M; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;

        child[u].push_back(v);
        child[v].push_back(u);
    }

    vector<bool>seen(N,false);

    int s=0;

    //　全ての頂点でdfsをして、seenが全て訪問済みになるまでやる。
    for (int i=0; i<N; i++) {
        if (!seen[i]) {    // 訪問してない頂点であればdfsをして、連結成分としてカウント
            dfs(i,child,seen);
            s++;
        }
    }

    cout << s << endl;
}