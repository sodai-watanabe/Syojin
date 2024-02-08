// B問題　seak words (snuke探し) 9/11
// 要復習 2/8 ok
// 2次元文字列、"snuke"の文字列を探して座標を答える。8方向。
// 教訓：2次元座標で方向で探す→方向配列を用意。
// 教訓：seak words → 全マス探索し、それぞれに対して方向配列の要素数分をループで試す。

#include <bits/stdc++.h>
using namespace std;
int H,W;

// 方向ベクトルを用意
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

int main () {
    cin >> H >> W;

    // 2次元文字列
    vector<string>S(H);
    for (int i=0; i<H; i++) {
        cin >> S[i];
    }

    // 全マスを一つずつ探索
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {

            // 決めたマスから探す方向を決める。
            for (int k=0; k<8; k++) {
                int x = j; 
                int y = i;
                string T = "snuke";
                vector<pair<int,int> >P;  // 座標を管理。後に出力するため

                // 決めたマスから決めた方向に5文字分を探す。
                for (int l=0; l<5; l++) {
                    if (x<0 || W<=x || y<0 || H<=y) break; // 配列外参照を防ぐ
                    if (S[y][x]!=T[l]) break;              // "snuke"ではない場合は終了
                    pair<int,int>p = make_pair(x,y);       // "snuke"の可能性がある場合、座標を追加
                    P.push_back(p);
                    x+=dx[k];  // 決めた方向へ座標を一つ進める。
                    y+=dy[k];
                }

                // 管理されてる座標が5個、つまりsnukeの場合に座標を出力
                if (P.size() == 5) {
                    for (auto p : P) {
                        cout << p.second+1 << ' ' << p.first+1 << endl;
                    }
                    return 0;
                }
                

            }
        }
    }



}