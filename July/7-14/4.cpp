// クイックソート
// https://algo-method.com/tasks/442
// 真ん中keyよりも小さい要素は配列L,大きい要素は配列Rへ入れる。
// これを再帰的に繰り返してR,Lを作る。
// 最後にL,A[key],Rの順に結合する

// 覚える：配列1.insert(配列1.end(), 配列2.begin(), 配列2.end());   配列1と配列2を連結

#include <bits/stdc++.h>
using namespace std;

vector<int> quick (vector<int>&A) {   // 別にvoidでもよかった。
    vector<int>L;
    vector<int>R;

    if (A.size() == 0) return A;

    int N = A.size();
    int X = N/2;

    for (int i=0; i<N; i++) {
        if (i == X) continue;
        if (A[i] < A[X]) L.push_back(A[i]);
        if (A[i] >= A[X]) R.push_back(A[i]);
    }

    quick(L);
    quick(R);

    L.push_back(A[X]);

    L.insert(L.end(), R.begin(), R.end());  // Lの末尾にRを挿入。配列の連結

    return A=L;
}

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    quick(A);

    for (auto a : A) {
        cout << a << " ";
    }
}