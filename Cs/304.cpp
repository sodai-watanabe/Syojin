// virus
// 人がいる座標がいくつか渡される。virusは距離D以内にいる人に感染する。人１が感染して十分時間が経った時、誰が感染しているか。
// 教訓：DFSでやる。queでやってみた。
// 教訓：ルートが出る時は2乗して整数で扱うのが鉄則。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, D;
    cin >> N >> D;

    vector<pair<int,int> >P(N); //　座標を管理
    for (int i=0; i<N; i++) {
        cin >> P[i].first;
        cin >> P[i].second;
    }

    vector<vector<int> >ff(N); // 隣接リスト

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i==j) continue;
            int x1 = P[i].first;
            int y1 = P[i].second;
            int x2 = P[j].first;
            int y2 = P[j].second;

            int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

            if (dist <= D*D) {  // ２点間距離がD以内の時は隣接していると見ることができる。
                ff[i].push_back(j);
                ff[j].push_back(i);
            }
        }
    }

    // 感染してない時は-1.
    vector<int>virus(N,-1);
    queue<int>que;
    
     // 人１は感染しているとして初期化
    que.push(0); 
    virus[0] = true;

    // queが空になるまで
    while (!que.empty()) {
        int v = que.front(); // 先頭を取り出す
        que.pop();

        for (auto c : ff[v]) {  // 隣接リストを用いて、隣の人をみる。
            if (virus[c]!=-1) continue;  // すでに隣人が感染していたらスルー

            virus[c]=virus[v]+1;
            que.push(c);  // 子が感染したら、queに追加。
        }

    }

    for (auto v : virus) {
        if (v!=-1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}