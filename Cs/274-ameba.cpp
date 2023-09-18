// 親から二つのamebaに分裂。各amebaは何回親を辿るとameba1につくか。
// 方針：親配列parentを持つ。子ansは親ans+1で求められる。
// 今回は、bfsでやってしまったが上の解法であればもっとシンプルに解けた。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int>A(N);
    map<int,pair<int,int> >mp;

    for (int i=0; i<N; i++) {
        cin >> A[i];
        mp[A[i]].first = 2*(i+1);
        mp[A[i]].second = 2*(i+1)+1;
    }

    map<int,int>dist;
    dist[1]=0;

    queue<int>que;
    que.push(1);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        if (!dist.count(mp[v].first)) {
            dist[mp[v].first] = dist[v]+1;
            que.push(mp[v].first);
        }
        if (!dist.count(mp[v].second)) {
            dist[mp[v].second] = dist[v]+1;
            que.push(mp[v].second);
        }     
    }


    for (int i=1; i<=2*N+1; i++) {
        cout << dist[i] << endl;
    }
}