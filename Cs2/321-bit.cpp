// K番目の321-number  要復習 9/24
// 321-numberの性質を見極める
// 性質：0~9までの数字どれかが一つづつ使われる。sortすると321-numberになる。
// 方針：使う数字を選ぶためにbit全探索。探索で得られた数字は321-numberだがKとは無関係。
// 方針：得られた数字はとりあえず配列で保管。最後にsortして、321-numberの集合を小さい順に並べ、K番要素を出力。
// 教訓：選ぶ選ばないの2通りの重ね合わせ → bit全探索
// 教訓：0~9の選択を01で表現したもの(2進数)と、それによって表現される数字(10進数)の順番は対応していない。
// 教訓：bit全探索 2進数から10進数へ → x=x*10+j を用いて更新していく。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    // K番目の321-numberを求める
    int K;
    cin >> K;

    // 全探索によって得られた321-numberを保管する配列。
    vector<ll>a;

    // 0~9の数字のどれを選ぶかを探索。2^10通り。
    for (int i=1; i<=(1<<10); i++) {

        // 探索された数字の組み合わせで表現される10進数の数字。
        ll x=0;

        // 探索された2進数から10進数の321-numberに変換する。
        for (int j=9; j>=0; j--) {
            // 探索された2進数のj桁目が1の場合は、xの1桁目に追加される。元のxは左に押し出すイメージ。
            if ((i>>j)%2==1) {
                x = x*10 + j;
            }
        }

        // 探索された321-numberを保管。10進数としての大きさの順番は全く関係ない。
        a.push_back(x);
    }

    // 保管された321-numberの順番はバラバラなのでsortする。
    sort(a.begin(),a.end());

    // K番目の321-numberを出力。
    cout << a[K] << endl;




    // 以下、間違った解法
    // Kという数と、321numberの順番が対応していると勘違い。
    // Kのみを見ているが、Kという数字が321numberのK番目とは限らない。
    // 例えばK=6 → K=110 → 21 となるが、21は321numberの6番目ではない。6番目は6である。
    
    // int x = 0;
    // for (int j=9; j>=0; j--) {
    //     if ((K>>j)%2==1) {
    //         x = x*10 + j;
    //     }
    // }
    // cout << x << endl;

}