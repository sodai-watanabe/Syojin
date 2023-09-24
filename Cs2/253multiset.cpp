// multiset query 要復習　9/24
// map<ll,ll>で要素とその個数を管理して実装したが、なぜかRE。
// query1:xを追加  query2:xをc回削除。xがなくなった時点で削除は終了。 query3:要素のmaxとminの差を出力
// 教訓：multisetの要素削除(一つだけ) → st.erase(st.find(x))とする。
// 教訓；multisetで st.erase(x) → xが複数入っていた場合、全てのxが削除されてしまう。
// 教訓：multisetのst.find(x) → xのitrを返す。xが存在しない場合はst.end()を返す。
// 教訓：itrが指す要素にアクセス → ll maxx = *st.rbegin() などとする。
// 教訓：rbegin()で末尾要素のitrを返す。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    // Q回のqueryを受け取る。
    ll Q;
    cin >> Q;

    // 要素を保持するmultiset.
    multiset<ll>st;

    // queryを受け取る。
    for (ll i=0; i<Q; i++) {
        int q;
        ll x;
        cin >> q;

        // 1:x要素追加
        if (q==1) {
            cin >> x;
            st.insert(x);
        }

        // 2:x要素をc回削除
        if (q==2) {
            ll c;
            cin >> x >> c;
            // xをc回削除
            for (int i=0; i<c; i++) {
                // xがmultisetに存在するかを確認。
                auto it = st.find(x);

                // itrがend()を返したらxは存在しない。
                if (it == st.end()) break;

                // 存在する場合はxを削除。
                // erase(x)とするとxが全て消える。
                // 一つづつ消したいので、erase(st.find(x))とする。
                st.erase(it);
            }
        }

        
        // 3:max-minを出力
        if (q==3) {

            // 先頭が最小、末尾が最大。
            // *itrとすることで、要素にアクセスできる。
            ll maxx = *st.rbegin();
            ll minx = *st.begin();
            cout << maxx - minx << endl;
        }
    }



    // map<ll,ll>mp;

    // for (ll i=0; i<Q; i++) {
    //     int q;
    //     ll x;
    //     cin >> q;

    //     if (q==1) {
    //         cin >> x;
    //         mp[x]++;
    //     }

    //     if (q==2) {
    //         ll c;
    //         cin >> x >> c;
    //         ll del = min(c,mp[x]);
    //         cout << "del:" << del  << "mp[x]" << mp[x] << endl;
    //         mp[x]-=del;

    //         if (mp[x]<=0) mp.erase(x);   
    //     }


    //     if (q==3) {
    //         ll maxx = mp.rbegin()->first;
    //         ll minx = mp.begin()->first;
    //         cout << maxx - minx << endl;
    //     }
    // }
}