// make Takahashi happy 要復習 8/22
// dfs
// 復習：i→H,j→Wの対応を逆にしてしまった..
// 問題:H*Wマスが与えられマスには数字。下または右への移動で左上から右下まで移動。同じ数字を通らない経路は何ルートあるか。
// 教訓:条件を満たす経路が何通りあるか→dfs
// 教訓:dfsは再帰関数で実装。終了条件を忘れない。
// 教訓:dfs→再帰関数内で次の状態にdfsを配るイメージ。隣接リストならfor文で、マス移動なら移動し得る一つ先のマスで自分自身dfsを呼び出す。
// 教訓:関数切り分けで、どの関数でも共通で使いたい変数はgrobalに置くと便利。初期値無しなら0で初期化される。
// 教訓:関数の引数。① &A参照→Aは変化させない。　② Aそのまま→Aは関数処理内で変化し得る。



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int H; int W;  // grobal変数。関数切り分け時、mainとdfsで共通して使いたいものはgrobalにすると便利。
int ans;       // grobal変数は何も書かないと0で初期化される
set<int>st;


// ansを作る関数dfs。マス情報Aを参照。(i,j)マスがスタート。setはdfs呼び出しのたびにリセットするので参照でない！
void dfs (vector<vector<int> >&A, int i, int j, set<int>st) {

    // set内に今のマスの数字が存在したら終了
    if (st.count(A[i][j])) {
        return;
    }

    // 今いるマスの数字をsetへ追加
    st.insert(A[i][j]);

    // dfsを次のマスへ配っていく
    if (j+1<W) {           // 右のマスへ。配列外参照のケア。
        dfs(A,i,j+1,st);   // 右のマスからルート検索を始める。右のマス用のsetを新たに用意して再スタートするので、setは参照でない。
    }
    if (i+1<H) {           // 下のマスへ。同様。
        dfs(A,i+1,j,st);
    }

    if (i==H-1 && j==W-1) { // 右下のマスに辿り着いたら終了。果てについた、と言う意味。また始点に戻る。
        ans++;              // 始点に戻されることなく右下マスに辿り着けた→条件をみたすルートである！のでansに加算。
        return;             // そのルートは完了。始点に戻る。
    }
}



int main () {
    // int H, W;      // grobal変数を再度mainで宣言するとバグになるので厳禁
    cin >> H >> W;    // grobalはそのまま入力できる。

    vector<vector<int> >A(H,vector<int>(W));  // マスの情報。これ以降いじらない。

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> A[i][j];
        }
    }

    dfs(A,0,0,st);     // 始点は(0,0)として、ansを作る。
    cout << ans << endl;
}