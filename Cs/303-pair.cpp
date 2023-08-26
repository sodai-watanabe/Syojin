// 8/26 自力AC
// 教訓：座標管理→２次元配列は計算量overなので、pairで持つ。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int N,M,H,K;
    cin >> N >> M >> H >> K;

    string S;
    cin >> S;

    set<pair<int,int> >item;           // itemが置いてある座標をsetで管理

    for (int i=0; i<M; i++) {
        int x,y;
        cin >> x >> y;
        pair<int,int>p = make_pair(x,y);
        item.insert(p);
    }

    pair<int,int> now = make_pair(0,0); // 現在いる座標
    int life = H;

    for (int i=0; i<N; i++) {  // Sの文字を見ていく
        life--;
        if (life<0) {          // lifeが負でアウト
            cout << "No" << endl;
            return 0;
        }

        if (S[i]=='R') now.first++;
        if (S[i]=='L') now.first--;
        if (S[i]=='U') now.second++;
        if (S[i]=='D') now.second--;


        if (item.count(now) && life<K) {
            life = K;
            item.erase(now);  // itemの消費し忘れ注意
        }
    }

    cout << "Yes" << endl;
    return 0;
}