// mex  8/20, 復習1/14
// 入力→N,K,[A1....AN]
// 配列Aの中からK個の要素を選ぶ。0から1つずつ数えて、初めてK個の要素内に入ってないものの最大値を出力。
// K個の選び方は様々にあるけれど、そのうちの最大値ということ。
// 教訓：重複または順序に意味がない時はsetが有効
// 教訓：数列内の存在判定問題はsetが有効

// ex)入力
// 7 3
// 2 0 2 3 2 1 9

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll N, K;
    cin >> N >> K;


    // 重複や順序が意味がないので、ひとまず全てsetに入れる
    set<ll>A;
    for (ll i=0; i<N; i++) {
       	int a ;
       	cin >> a;
        A.insert(a);
    }

    // 要素を小さい順に並べて、0から一つずつ要素を見た時に初めて存在しない数字が最大のmex
    for (ll i=0; i<=K; i++) { // 0から一つずつ探索。

        if (!A.count(i)) {// 今見てる数がsetに存在しなければ、それがmex
            cout << i << endl;
            return 0;
        }
    }

    // 0,1,2,....,K-1となり、全て要素が含まれていたらKがmex
    cout << K << endl;
}