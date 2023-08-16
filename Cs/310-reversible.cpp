// reverse
// 文字列がいくつか入力される。前後反転は同じものとしたときに、入力された文字列は何種類あるか。
// 教訓：文字列の反転→ reverse(s.begin(),s.end()); 代入ではなく、sがそのまま反転した文字列になる「操作」の関数。
// 教訓：種類数→set内にはまだ入ってないものであればans++となる。setには入力s及びその反転したものをその都度追加する。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    set<string>S;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;

        string copy = s;
        reverse(copy.begin(),copy.end());

        if (!S.count(s) && !S.count(copy)) {
            S.insert(s);
        }    
    }

    cout << S.size() << endl;
}