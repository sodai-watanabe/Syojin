// https://algo-method.com/tasks/361
// 要復習greedy
// 箱は小さい順に並んでいる。いろんなサイズのボールを箱にできるだけ多く入れる問題。
// 結論：未探索の箱の中で、最小の箱に入るボールを後先考えずに貪欲に入れる。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int>A;
    vector<int>B;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }

    int count = 0;

    vector<bool>used(n,false);   //　ボールが入っているかどうか

    for (int i=0; i<m; i++) { //箱を小さい順に、順番に見る。

        for (int j=0; j<n; j++) { //ボールを順番に見る。順番はなんでも良い
            if (used.at(j)) continue;   // 探索済みならスルー

            if ( A.at(j) <= B.at(i)) {  // 大きさ的に箱iにボールjが入るならば、貪欲に入れる。
                used.at(j) = true;    // 探索済み
                count++;
                break;    // 箱にボールを入れたら、ボールの探索は終了
            }
        }
    }
    cout << count << endl;
}