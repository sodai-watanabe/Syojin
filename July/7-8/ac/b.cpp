// https://atcoder.jp/contests/abc309/tasks/abc309_b
// rotate問題
// 同じ配列を二つ用意して、片方に書き込んでいく。
// 以下のようにfor内のifでまとめたらよかった。

// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//       if(i==0||j==0||i==n-1||j==n-1){
//         if(i==0&&j<n-1) ans[i][j+1]=a[i][j];
//         if(i<n-1&&j==n-1) ans[i+1][j]=a[i][j];
//         if(i==n-1&&j>0) ans[i][j-1]=a[i][j];
//         if(i>0&&j==0) ans[i-1][j]=a[i][j];
//       }
//       else{
//         ans[i][j]=a[i][j];
//       }
//     }
//   }


#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<string>A(n);
    vector<string>B(n);

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        A[i] = s;
        B[i] = s;
    }

    B[0][0] = A[1][0];
    B[0][n-1] = A[0][n-2];
    B[n-1][n-1] = A[n-2][n-1];
    B[n-1][0] = A[n-1][1];

    for (int i=1; i<n-1; i++) {
        B[0][i] = A[0][i-1];
    }
    for (int i=1; i<n-1; i++) {
        B[i][n-1] = A[i-1][n-1];
    }
    for (int i=1; i<n-1; i++) {
        B[n-1][i] = A[n-1][i+1];
    }
    for (int i=1; i<n-1; i++) {
        B[i][0] = A[i+1][0];
    }

    for (int i=0; i<n; i++) {
        cout << B[i] << endl;
    }
}