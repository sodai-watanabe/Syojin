// .と#からなる2次元文字列。4つの#が正方形の個数を求めよ。  9/18 要復習
// 方針：#の位置をsetで管理。そのうち2点が決まると、その辺がなす正方形の位置は決定する。決定した他の2点が#であれば正方形。
// 教訓：pairを作る → pair<int,int>p(a,b)で作れる。make_pair不要。
// 教訓：2次元文字列正方形検出 → 2点を選ぶと他2点も決定する。選んだ2点の縦横の差di,djを用いて他2点を表す。
// 教訓：2点を選ぶと実際は2通りの正方形が決まるが、半時計周り制限すれば1通りに決まる。
// 教訓：1点で正方形検出されると、他3点でも同じ正方形が検出されるため最終的な答えがans/4とする。

#include <bits/stdc++.h>
using namespace std;

int main () {
    set<pair<int,int> >S;

    for (int i=0; i<9; i++) {
        string s;
        cin >> s;

        // #のマスをsetで管理
        for (int j=0; j<9; j++) {
            if (s[j]=='#') {
                pair<int,int>p = make_pair(i,j);
                S.insert(p);
            }
        }
    }

    int ans = 0;

    // マスから全探索で2点を選ぶ。
    for (auto a : S) {
        for (auto b : S) {
            // 異なる2マスを見る
            if (a!=b) {

                //       a
                //  b
                //       d
                //  c        という位置関係を仮定する。これは左回りの配置。

                int di = b.first - a.first;  // 2マスの縦差
                int dj = a.second - b.second;// 2マスの横差


                // 選んだ2点から、他2点が決まる。a,bの縦横差を使って表現
                pair<int,int>c (b.first+dj, b.second+di);
                pair<int,int>d (b.first+dj-di, b.second+di+dj);

                // 他2点(c,d)が'#'の時、正方形が検出。
                if (S.count(c) && S.count(d)) {
                    ans++; 
                }
            }
        }
    }

    // 4点分の正方形がカウントされるので4で割る。
    cout << ans/4 << endl;
}