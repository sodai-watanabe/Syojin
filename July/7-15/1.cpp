// https://algo-method.com/tasks/324
// 二次元座標dp
// 端の条件をつけて、配列外参照を防ぐ
// for文の中でifのみで処理を切るときはcontinueを忘れない。

#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<vector<int> >A(4, vector<int>(4));
    for (int i=0; i<4; i++) {
        cin >> A[0][i];
    }

    for (int i=1; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (j == 0) {
                A[i][j] = A[i-1][j]+A[i-1][j+1];
                continue;    // ここでcontinueしないと、for内全て実行される
            }
            if (j == 3) {
                A[i][j] = A[i-1][j]+A[i-1][j-1];
                continue;    // ここも同じ
            }
            A[i][j] = A[i-1][j-1]+A[i-1][j]+A[i-1][j+1];
        }
    }
    cout << A[3][3];
}