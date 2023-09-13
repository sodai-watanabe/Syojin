// 問題：配列がある。1度の操作では、1つの要素の数を-1しまた別の要素を+1できる。最大値と最小値の差が1となるまでに何回の操作が必要か求めよ。
// 方針：不変量は総和S.また終状態の要素はXまたはX+1のみ。X+1の要素数をrとするとS=NX+rが成り立つことに注目。
// 方針：始状態と終状態で要素の差から操作数がわかる。
// 教訓：何回操作をしてもよくて最適解を求めよ系問題　→ 不変量に注目する。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll N;
    cin >> N;
    vector<ll>A(N); // 配列が与えられる。
    ll sum = 0;     // 総和
    for (ll i=0; i<N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    sort(A.begin(),A.end());  // sort忘れずに

    // 終状態の要素はXまたはX+1のみ。X+1の要素数rとするとsum=NX+rが成り立つ。
    ll X = sum/N;
    ll r = sum%N;

    // 終状態の配列を用意
    vector<ll>B(N);

    for (int i=0; i<N; i++) {
        if (i<N-r) B[i] = X;
        else B[i] = X+1;
    }

    ll count = 0;


    for (int i=0; i<N; i++) {
        int gap = B[i]-A[i];  // 始状態と終状態で同じindex要素の差

        // 差が正の場合、操作数として追加。
        // gapを差の絶対値にして、それらの総和の半分でも良い。
        if (gap>0) {
            count+=gap;
        }
    }
    cout << count << endl;

}