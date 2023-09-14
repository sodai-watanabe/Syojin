// 頂点数がINFなdfs.9/14   要復習 
// 方針：隣接リストもseen配列も持てない。→ 連想配列で対応。
// 教訓：要素数がINFの時 → 配列の代わりにmapを使う。
// 教訓：map<int, vector<int> >child で、child[key].push_backとすると、既にkeyが存在すればそこに追加、存在しない場合は新たに生成される。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;

// 隣接リスト、seen配列の代わりにmapを用いてdfs
void dfs (int v, map<int, vector<int> >&child, map<int, bool>&seen) {
    if (seen[v]) return;  // 訪問済み頂点はスルー 
    seen[v] = true;       // 訪問済みに更新

    // 隣接頂点にdfsを配る。
    for (auto nv : child[v]) {
        if (!seen[nv]) {  // 未訪問の場合のみdfsを実施
            dfs(nv, child, seen);
        }
    }
}

int main () {
    cin >> N;

    // 隣接リストの代わりにmap
    map<int, vector<int> >child;
    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        // child[a]が存在しない場合は自動で生成され、存在する場合はそこに追加される。
        child[a].push_back(b);
        child[b].push_back(a);
    }

    // seenも配列だと要素数がINFになるので持てない。mapを用いて対応。
    map<int, bool>seen;

    // 1階(0頂点)からスタート。0頂点から到達できる頂点はseenがtrueになる。
    dfs(0,child,seen);

    int ans_v = 0;

    // 0頂点から到達できる頂点のうち、最も数が大きいものを探す。最も階が高いもの。
    for (auto c : seen) {
        if (c.second) {
            ans_v = max(ans_v,c.first);
        }
    }

    cout << ans_v+1 << endl;
}