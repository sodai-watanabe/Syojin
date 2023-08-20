// medicine
// a[i]日間,b[i]錠飲む薬がN個ある.1日に飲まなければいけない薬の総数がK個以下になるのは何日目かを求める。
// 方針：初日に飲む薬が一番多いので、これをsumとする。薬をsumから減らしていき、sum<=Kとなった時点の日にちを求める。
// 教訓：日にちを1日ずつ探索するのではなく、薬個数の変わり目飲みを探索する。
// 教訓：両端は特殊になる場合がある。初日の時点ですでにsum<=Kの場合は1日目が答え。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll> >P;

    for (ll i=0; i<N; i++) {
        ll a,b;
        cin >> a >> b;
        pair<ll,ll>p = make_pair(a,b);
        P.push_back(p);
    }

    sort(P.begin(), P.end());

    ll sum = 0;

    for (ll i=0; i<N; i++) {
        sum += P[i].second;
    }

    // 両端の時は、特殊なケースになることもある。
    if (sum <= K) { 
        cout << 1 << endl;
        return 0;
    }

    for (ll i=0; i<N; i++) {
        sum -= P[i].second;

        if (sum <= K) {
            cout << P[i].first+1 << endl;
            return 0;
        }
    }

}
