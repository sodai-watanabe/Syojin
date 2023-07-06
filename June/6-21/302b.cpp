#include<bits/stdc++.h>
using namespace std;

int dx[8] = {0,1,1,1 ,0 ,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0 ,1 };

int main () {
    int h, w;
    cin >> h >> w;

    vector<string>S(h);
    for (int i=0; i<h; i++) {
        cin >> S.at(i);
    }

    // まずはスタートマスを全探索
    for (int si=0; si<h; si++) {
        for (int sj=0; sj<w; sj++) {
            // スタートマスから方向を決める
            for (int k=0; k<8; k++) {
                string T = "snuke";
                // i,jはスタートマスの添え字
                int i = si;
                int j = sj;
                // snukeの5文字を、上で決めた方向に探索
                for (int t=0; t<5; t++) {
                    // 範囲外参照を回避
                    if (i<0 || w<=i || j<0 || h<=j) break;
                    // snukeになっていなければ、途中の文字でもbreak
                    if (S[i][j] != T[t]) break;
                    // もし、4回目まで行ったら、それはsnuke確定。
                    if (t==4) {
                        // 出力する。
                        for (int l=0; l<5; l++) {
                            cout << i+1 << " " << j+1 << endl;
                            i += dx[k];
                            j += dy[k];
                        }
                        return 0;
                    }
                    i += dx[k];
                    j += dy[k];
                }
            }
        }
    }
}