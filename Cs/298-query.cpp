// query  8/22 要復習
// (1,i,j)(2,i)(3,i)の3パターンのqueryがQ回入力される。箱がN個あり、数字カードもある。
// query1→箱iに数字jを入れる、query2→箱i中のカードを昇順出力、query3→カードiが入った箱を昇順出力
// 教訓:query問題→queryに応じて条件分岐で処理をかく。
// 教訓:計算量→データ構造を複数持つことを恐れない。今回はmap<int,set<int>>mp;としたことでfor内でset.countをしてTLE。
// データ構造を複数持つことで、一つの処理の計算量を落とせる。今回はvectorを二つ持つことで、for内は要素出力のみで良くなった。
// 教訓：配列の初期化に注意。直感的に分かりやすい命名にしよう。
// 復習：1/15 ok

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, Q;
    cin >> N >> Q;

    // 教訓:配列名は直感的に分かりやすいもので。勘違いが起きると初期化で設定ミスが起きる。
    vector<vector<int> >cards(N+1);
    vector<set<int> >boxies(1000000); // 初期化でミスった。boxies(N)としていた。boxiesの要素数は箱の数ではなく、入力されうる数字の最大値。なぜsetかというと、箱は重複は考えないから。

    for (int i=0; i<Q; i++) {
        int q;
        cin >> q;

        // query1
        if (q == 1) {
            int i,j;
            cin >> i >> j;
            cards[j].push_back(i); // 箱jにカードiを入れる。
            boxies[i].insert(j);   // カードiは箱jに入っている。(上と同じことを表現を変えて)

        // query2
        } else if (q==2) {
            int i;
            cin >> i;
            sort(cards[i].begin(),cards[i].end()); //昇順
            for (auto v : cards[i]) {
                cout << v << ' ';  // 箱iに入っている数字を出力
            }
            cout << endl;

        // query3
        } else if (q == 3) {
            int i;
            cin >> i;
            for (auto b : boxies[i]) { // setは勝手にsortされる
                cout << b << ' '; // 数字iが入っている箱を出力
            }
            cout << endl;
        }
    }
}