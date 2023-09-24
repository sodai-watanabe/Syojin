#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll Q;
    cin >> Q;

    map<ll,ll>mp;

    for (ll i=0; i<Q; i++) {
        int q;
        ll x;
        cin >> q;

        if (q==1) {
            cin >> x;
            mp[x]++;
        }

        if (q==2) {
            ll c;
            cin >> x >> c;
            ll del = min(c,mp[x]);
            // cout << "del:" << del  << "mp[x]" << mp[x] << endl;
            mp[x]-=del;

            if (mp[x]<=0) mp.erase(x);   
        }


        if (q==3) {
            ll maxx = mp.rbegin()->first;
            ll minx = mp.begin()->first;
            cout << maxx - minx << endl;
        }
    }
}