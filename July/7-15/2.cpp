// https://algo-method.com/tasks/325
// ２次元dp
// 前問と同じ要領
// N×Nマスで「左上」「真上」「右上」の数字の総和を100で割ったあまり。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    
    vector<vector<int> >A(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        cin >> A[0][i];
    }

    for (int i=1; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (j == 0) {
                A[i][j] = (A[i-1][j]+A[i-1][j+1])%100;
                continue;    // ここでcontinueしないと、for内全て実行される
            }
            if (j == N-1) {
                A[i][j] = (A[i-1][j]+A[i-1][j-1])%100;
                continue;    // ここも同じ
            }
            A[i][j] = (A[i-1][j-1]+A[i-1][j]+A[i-1][j+1])%100;
        }
    }
    cout << A[N-1][N-1];
}