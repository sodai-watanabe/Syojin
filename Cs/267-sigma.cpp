// index*A 要復習　9/19 なぜかACできない
// 計算の工夫系
// 問題：N,M,A=(A1,A2,...,AN)が与えられる。Aの連続部分列B=(B1,...,BM)に対して、Σi*Biの最大値を求めよ。
// 方針：次のΣは直前のΣとAの要素を用いて表すことができる。これにより愚直計算を避けられる。
// 教訓：一つずつshiftしながら試す系問題 → 直前のものとその端点に注目して工夫して計算する。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int N,M;
    cin >> N >> M;
    vector<ll>A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    ll t=0;
    ll s=0;

    // 先頭からM個要素の和をとる。計算の工夫で用いる。
    for (int i=0; i<M; i++) {
        t+=A[i];
    }
    // 先頭からM個要素のΣを計算。Σの初項。
    for (int i=0; i<M; i++) {
        s+=A[i]*(i+1);
    }

    ll ans = 0;

    // 次のΣは、直前のΣからAの先頭からM要素の和tを引き、右端のA要素を新たに加算することで得られる。
    for (ll i=0; i<N-M+1; i++) {
        ans = max(ans,s);
        ll ns = s-t+M*A[i+M]; // 次のΣを工夫計算により得る。
        ll nt = t-A[i]+A[i+M];// AのM個要素の和の次の項。次項は直前のtから左端を引き、右端を加算すると得られる。
        s=ns;
        t=nt;
    }

    cout << ans << endl;
}