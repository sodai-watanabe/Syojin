// recursionによるフィボナッチ数列
// 正しこれだと計算効率がかなり悪い
// 次問題でメモ化を扱う

#include <bits/stdc++.h>
using namespace std;

int func (int n) {
    if (n==0) return 0;
    if (n==1) return 1;

    return func(n-1)+func(n-2);
}

int main () {
    int n;
    cin >> n;

    cout << func(n) << endl;
}