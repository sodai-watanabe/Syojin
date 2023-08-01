// バブルソート
// https://algo-method.com/tasks/439
// 配列で、隣の要素との大小を判定し入れ替える。入れ替えが1度も起きなければsort完了でループを抜ける。
// fragの置き方、更新に注意。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int>A(N);

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    bool frag; // whileでfragを入れる時は外で宣言

    while (!frag) {  
        frag = true;  // 以下の条件で、frag=falseに更新されなければループが抜けられるように。
        for (int i=0; i<N-1; i++) {  // 配列要素を一つづつ見て、隣同士の大小を判定
            if (A[i]>A[i+1]) {
                swap(A[i],A[i+1]);
                frag = false;    // swapが起きたらまだループを続けるのでfrag=falseに更新。
            }
        }
        if (!frag) {  // swapが起きたら(要素の順番に変化がある)要素を出力
            for (auto a : A) cout << a << " ";
            cout << endl;
        }
    }

}