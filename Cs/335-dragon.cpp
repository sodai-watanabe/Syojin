// 問題：1/12 座標でドラゴンが動く。UDLRのいずれかを受け取り、その方向に頭が移動する。
// 教訓：すべてのマスを追跡する必要はない。→ 変化するのは先頭と末尾のみ。
// 教訓：vectorのinsert(先頭追加)はO(N)。push_backは高速。
// 教訓：vectorで先頭追加したい→reverseしてpush_back

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main () {
    int Q;
    cin >> N >> Q;

    vector<pair<int,int> >po;

    for (ll i=1; i<=N; i++) {
        pair<int,int>p(i,0);
        po.push_back(p);
    }
    // 先頭追加するためにreverse
    reverse(po.begin(), po.end());

    // mapの要素込み初期化のやり方わからない
    map<char,int>mp;
    mp['U']=0;
    mp['D']=1;
    mp['L']=2;
    mp['R']=3;

    for (ll i=0; i<Q; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            char C;
            cin >> C;
            // 末尾(dragonの頭)を指定
            auto head = po.back();
            // 末尾に動いた後の新しい頭を追加。
            pair<int,int>newhead(head.first+dx[mp[C]], head.second+dy[mp[C]]);
            po.push_back(newhead);
        } else if (q == 2) {
            int p;
            cin >> p;
            // reverseしてあるので、末尾からp番目を出力。(末尾からp番目 = po.size()-p)
            int a = po[po.size()-p].first;
            int b = po[po.size()-p].second;
            cout << a << ' ' << b << endl;
        }
    }

}