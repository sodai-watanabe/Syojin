// https://atcoder.jp/contests/abc310/tasks/abc310_c
// 問題：異なる文字列は何種類存在するかを求める。ただし、反転した文字列も元の文字列と同じものとする。
// 方針；文字列をsetでもつ。setに文字列を追加するとき、反転したものも同時に入れる。入力された文字列がsetに存在しなければans++とするる。
// 当初、setの要素数で答えを出そうとしたが、これではうまくいかない。

#include <bits/stdc++.h>
using namespace std;

int main () {
    set<string>S1;

    int N;
    cin >> N;

    int ans = 0;
    for (int i=0; i<N; i++) {
        string s;  // 文字列が入力される
        cin >> s;
        if (!S1.count(s)) ans++;   // setに文字列が存在しなければans++。
                                   // setにはこれまで入力された文字列と、その反転したものが入っている。
                                   
        S1.insert(s);      // setに存在しようがしなかろうが、とりあえず追加
        reverse(s.begin(),s.end());  // 反転したものも追加
        S1.insert(s);
    }

    cout << ans;
}