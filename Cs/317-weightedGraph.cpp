// 重みつき無向グラフ　要復習　9/13
// 問題：与えられた重みつき無効グラフで、頂点から別の頂点へ移動するときの重みの和のの最大値を求めよ。
// 方針：現在の頂点、現在のルートでの訪問済み頂点、現時点での重みの和、を保持しながらdfs。全ての頂点でdfsを行い、globl変数ansを更新していく。
// 教訓：dfs → 引数の更新は処理内で行わない。dfsを配るときに、"crr+c"のように和の形で引数に渡す。
// 教訓：dfs → 持つべき変数を引数ではなく、grobalにおいてそれを更新していくことがよくある。

#include <bits/stdc++.h>
using namespace std;
int N,M;
int ans;  // 和の最大値(答え)をgrobalに置き、これを更新していく。

// 引数(現在いる頂点、隣接リスト、訪問済み頂点配列、今までに通った道の重みの和)としてdfs
void dfs (int v, vector<vector<pair<int,int> > >&child, vector<bool>seen, int crr) {
    if (seen[v]) return;  // 既に訪問していたらスルー

    seen[v] = true;       // 訪問したので配列を更新
    ans = max(ans,crr);   // 今までの重みの和と答えの大きい方をansに格納。これで最大値がもとまる

    // dfsを配っていく
    for (auto nv : child[v]) {
        if (!seen[nv.first]) {  // 訪問済みでない時のみ処理を行う

            // 以下間違い。
            // crr自体を更新してはいけない。
            // crr += nv.second;
            // dfs(nv.first, child, seen, crr);

            // 以下正しい。
            // crr+nv.secondを引数に渡すことで、次のdfs内でのcrrが更新されているイメージ。
            dfs(nv.first, child, seen, crr+nv.second);
        }
    }
}

int main () {
    cin >> N >> M;
    vector<vector<pair<int,int> > >child(N+1);

    for (int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        pair<int,int> pa = make_pair(a,c);
        pair<int,int> pb = make_pair(b,c);
        child[a].push_back(pb);
        child[b].push_back(pa);
    }

    vector<bool>seen(N+1,false);

    // 全ての頂点スタートでdfsをする。ansが更新され、最大のansがもとまる。
    for (int i=1; i<=N; i++) { 
        dfs(i,child,seen,0);
    }

    cout << ans << endl;
}