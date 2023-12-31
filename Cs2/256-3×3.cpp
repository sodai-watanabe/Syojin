// 工夫した全探索 要復習 9/22,12/24→ok
// 問題：3×3マスがあり、３列3行のマスの和が与えられる。和の条件を満たすマスのパターン数を求めよ。
// 方針：9つのマスにおいて全ての通りを試すと30^9となりTLE.
// 方針：和の条件から、1列において2マスが決まるのもう1マスも自動的に決まる
// 方針：実質、左上の4マスが決まると全てのマスの数字が確定する→4マスのみの全探索。30^4であれば十分高速。
// 教訓：高速化問題　→ 条件の特徴から探索範囲を狭める

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    // 3列に対して、それぞれの3マスの総和
    vector<int>W(3);
    // 3行に対して、それぞれの3マスの総和
    vector<int>H(3);
    for (int i=0; i<3; i++) {
        cin >> H[i];
    }
    for (int i=0; i<3; i++) {
        cin >> W[i];
    }

    // パターン数
    int ans=0;

    // 左上の4マスのみで、取りうる値の範囲で全探索
    for (int a=1; a<=30; a++) {
        for (int b=1; b<=30; b++) {
            for (int d=1; d<=30; d++) {
                for (int e=1; e<=30; e++) {
                   
                    // 条件から、4マスが決まると自動的に他の5マスが確定する。
                    int c = H[0] - a - b;
                    int f = H[1] - d - e;
                    int g = W[0] - a - d;
                    int h = W[1] - b - e;

                    int iw = W[2]-c-f;

                    // 自動的に確定した5マスが、数字が取りうる範囲内にあるかをチェック。
                    if (c>0 && f >0 && g>0 && h>0 && iw>0 && g + h + iw == H[2]) {
                            ans++;
                    }

                }
            }
        }
    }

    cout << ans << endl;
}