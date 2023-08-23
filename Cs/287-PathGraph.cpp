// path graph  8/23 要復習
// 問題：グラフが一直線になっているかを判定  ①-②-③-④-⑤ 
// 方針：条件１,頂点数-辺数=1  条件2,:隣接頂点数は1または2。  条件3,グラフが連結
// 教訓；条件1,2だけだと、直線+cycleも満たしてしまう。グラフ連結も大切
// 教訓：グラフの連結判定→bfsでseenを作る。1回で全頂点訪問できたら連結成分は1つ。
// 教訓：bfs→隣接頂点を訪問する時、「未訪問の時のみ処理をする」を忘れない。


#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// seenを作る関数を切り分けて用意(bfs)
void bfs (vector<vector<ll> >&child, int i,  vector<bool>&seen, queue<ll>&que) { // seenやqueはlocalで用意し参照する。iは始める頂点。
    que.push(i);                   // 初めの頂点をqueへ

    while(!que.empty()) {          // queが空になるまで繰り返す。
        int v = que.front();
        que.pop();                 // 先頭を取り出す。
        seen[v]=true;              // 取り出された頂点は訪問済みとする。

        for (auto nv : child[v]) { // 取り出された頂点の子頂点を探索
            if (!seen[nv]) {       // 教訓：まだ訪問してないものだけ、①訪問済みにする②queに追加
                seen[nv]=true;
                que.push(nv);
            }
        }
    }
}

int main () {
    ll N,M;
    cin >> N >> M;  // grobal

    vector<vector<ll> >child(N);   // 隣接リスト

    for (int i=0; i<M; i++) {
        ll a,b;
        cin >> a >> b;
        child[a-1].push_back(b-1);
        child[b-1].push_back(a-1);
    }

    if (N-M != 1) {                 // 条件1:頂点数-辺数=1
        cout << "No" << endl; 
        return 0;
    }

    ll one = 0;                     // 条件2:隣接頂点数は1または2。隣接頂点数が1の頂点は両端のみなので2つのみ。
    for (auto ch : child) {
        if (ch.size() == 1) one++;
        else if (ch.size()!=2) {    // 1または2以外のものはその場でアウト
            cout << "No" << endl;
            return 0;
        }
    }

    vector<bool>seen(N,false);      // 切り分けたbfsを使うために、seenとqueを用意
    queue<ll>que;

    // seenを作る。
    bfs(child,0,seen,que);


    // seen要素が全てtrue→全頂点訪問済み→連結している
    // 連結していなければアウト。
    for (auto s : seen) {
        if (!s) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 隣接頂点数=1の頂点が2つでないときはアウト(両端の2つが隣接数1,その他は2)
    if (one != 2) {
        cout << "No" << endl;
        return 0;
    } 

    // 最後まで潜り抜けたものだけOK
    cout << "Yes" << endl;
    return 0;
}