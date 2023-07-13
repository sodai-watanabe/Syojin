// https://algo-method.com/tasks/441
// 挿入ソート
// 要素数Nの配列をsortしましょう
// k=1,2,3...,N-1について
// 変数posにkを代入
// pos!=0かつA[pos-1]>A[pos]の間、A[pos-1]>A[pos]を入れ替えpos--とする。
// あんまり計算効率は良くない、、、

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int>A(N);

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    for (int k=1; k<N; k++) {   // 要素数N配列のkばんめに注目
        int pos = k;   //注目index=pos
        while (pos!=0 && A[pos-1]>A[pos]) { // posは減少するので、pos!=0. 左要素の方が大きい間繰り返す。
            swap(A[pos-1], A[pos]);  //　右が大きくなるように入れ替える
            pos--;  // 注目要素から左の要素を順に見ていく
        }
        for (int i=0; i<N; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

}