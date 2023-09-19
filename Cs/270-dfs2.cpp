// 激難しい　要復習9/19
// 問題：N頂点木が与えられる。また与えられた2頂点X,Yの単純パスの頂点経路X→Yを求めよ。
// 入力: N X Y
//      u v.....
// 方針：行き切りdfs.行き切ってからでないと良い経路かがわからないため。つまりYを始点にdfsして帰りがけにX→Yが得られる。
// 教訓：グラフ問題で、行き切らないと答えが出ない問題 → 「行き切りdfs」
// 教訓：→ bool型dfsとして、目的地に辿り着けるならtrueを返す。経路は考えず最終状態のみから条件をつける。
// 教訓：→ 子要素が自身の親でない(引き返し禁止)かつ子要素から目的地へ辿り着ける(dfs=true)場合のみ子要素にdfsを配りtrueを返す。
// 教訓：→ 上の場合以外はfalseを返す。
// 教訓：→ 行ききりdfsの引数には ①現在見ている頂点 ②現在の頂点の親頂点　が必要。

#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int N,X,Y;

// 行き切りdfs。現在見ている頂点vを始点にしてXまで行き切る。
bool dfs (int v,int p, vector<vector<int> >&child) {

    // Xにたどり着けたらansに追加しtrueを返す。
    // 途中のことは考えず、最終状態の条件をつける。
    if (v==X) {
        ans.push_back(v);
        return true;
    }

    // 現在の頂点がX出ないとき、その子要素にdfsを配る。
    for (auto c : child[v]) {

        // 現在見ている頂点の親には進めない
        if (c!=p) {

            // その子要素からでも目的地Xに辿り着ける場合のみansに追加。
            if (dfs(c,v,child)) {  // ここでdfs実行されているので、実質X~現在の頂点の一つ前までansに入っている。

                // 現在見ている頂点をansへ追加しtrueを返す。これでX~vまでのpathがansへ入り切ったのでtrueを返す。
                ans.push_back(v);
                return true;
            }
        }
    }
    // 上の条件から漏れた場合はXに辿り着けない場合なのでfalseを返す。
    return false;
}

int main () {
    cin >> N >> X >> Y;
    X--;
    Y--;
    
    vector<vector<int> >child(N);

    for (int i=0; i<N-1; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        child[u].push_back(v);
        child[v].push_back(u);
    }

    // Yから目的地Xまで探索しansを作る。始点Yの親は無いので-1で初期化。
    dfs(Y,-1,child);

    for (auto a : ans) {
        cout << a+1 << ' ';
    }
}