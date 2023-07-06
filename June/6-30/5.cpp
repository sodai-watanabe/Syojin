// https://algo-method.com/tasks/364
// 工夫のいるgreedy
// 問題文の流れに沿うとうまくいかない。
// 後ろから逆算で考える。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    int count = 0;

    while (n>0) {             // 問題文通りの流れで考えるとうまくいかない。後ろから逆算で考える。
        if (n%3 == 0) n/=3;   // nが3の倍数なら、3でわる
        else n -= 1;          // そうでなければ1を引く
        count ++;
    }

    cout << count << endl;
}