// https://atcoder.jp/contests/abc309/tasks/abc309_c
// 2重ループ回避問題
// ・愚直に全パターンやらずに、変わり目の情報のみ持てば十分。
// 二つの情報(日にちの長さ&個数)を持ちたいときはpairで持って、firstを優先的にsortで見通しが良くなることがある。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    // long longは書くの面倒なので省略して使えるように

int main () {
    long long N, K;
    cin >> N >> K;

    vector<pair<ll, ll> >P;

    ll sum = 0;

    for (int i=0; i<N; i++) {
        long long a, b;
        cin >> a >> b;
        pair<ll, ll>p;
        p.first=a;
        p.second=b;
        P.push_back(p);
        sum += b;
    }

    sort(P.begin(), P.end());

    if (sum <= K) {
        cout << 1 << endl;
        return 0;
    }


    for (int i=0; i<N; i++) {
        sum-=P[i].second;
        if (sum <= K) {
            cout << P[i].first+1 << endl;
            return 0;
        }
    }
}