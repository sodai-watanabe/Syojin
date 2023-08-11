// 教訓1:sortに比較関数を指定する方法。ラムダ式でかける。
// 教訓2:浮動小数は使わない。誤差が出るためACできない。→工夫して整数に直す。今回は分数不等式の分母を払って整数不等式に直す。

// 比較関数を指定する場合、コンパイルは　c++ -std=c++11 c.cpp　でやる。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    vector<int>B(N);

    for (int i=0; i<N; i++) {
        cin >> A[i];
        cin >> B[i]; 
        B[i]+=A[i];   
    }

    vector<int>ans(N);

    for (int i=0; i<N; i++) ans[i]=i;


    // ラムダ式
    // (int i, int j)のi,jはansの要素だと思う。(だからint型)
    sort (ans.begin(), ans.end(),  [&](int i, int j) {
        if (A[i]*B[j]==A[j]*B[i]) return i<j;   // 成功率が同率の場合は、番号の昇順(小さい方から)。小さいものが左にくるイメージ。trueの時,第一引数(i)が左。
        return (long long) A[i]*B[j]>(long long)A[j]*B[i];  // 一応、iの成功率>jの成功率と見ることができる。trueの時、第一引数(i)が左。
    });

    for (auto a : ans) cout << a+1 << ' ';
}
