// https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
// codility
// 配列要素のシフト
// 空配列の場合と、シフト回数が要素数よりも大きい時の処理に注意
#include <bits/stdc++.h>
using namespace std;

string main (int K, string &A) {
    if (A.size()==0) return A;
    if (A.size()<K) K%=A.size();

    rotate(A.begin(),A.begin()+A.size()-K,A.end());

    cout << A << endl;
}