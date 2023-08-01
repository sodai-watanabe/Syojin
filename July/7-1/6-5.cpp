// 練習必須
// https://algo-method.com/tasks/365
// 巡回セールスマン問題

#include <bits/stdc++.h>
using namespace std;

// 二頂点間の距離を求める関数。何度も実行する計算は煩雑なので切り分けよう
double calc (int i, int j, vector<double>&X, vector<double>&Y) {    //計算で使う数値はdoubleで揃える
    return sqrt((X[j]-X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i]));   // 自乗は2回掛けるだけ
};


int main () {
    // 入力
    int N;
    cin >> N;
    vector<double> X(N), Y(N);  //double注意
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    // 答え
    double res = 0.0;
    vector<bool> used(N, false);
    used[0] = true;

    int prev = 0;

    for (int i=0; i<N-1; i++) {   //　0<=i<N-1　につまづいた。ただ、n-1回ループを繰り返す。最後の点n-1から点0の分は入れない。
            int nex = -1;
            double min_dis = 1000000;

        for (int j=0; j<N; j++) {  // 次の点を見つける
            if (used[j]) continue; //探索済みはスルー

            double dist = calc(prev, j, X, Y);
            if (min_dis > dist) {  //　最短を更新。
                min_dis = dist;
                nex = j;  //次点の候補
            }
        }
        used[nex] = true;   //次点nexを探索済みにしておく
        res += min_dis;     //現点prevと次点nexの距離(最短を選んだ)を答えに加算

        prev = nex;    // 現点を更新
    }

    res += calc(prev, 0, X, Y);   // 最後の点n-1から点0の分の距離

    cout << fixed << setprecision(10) << res << endl;  // etprecision(10)で小数10桁を表示。doubleの時はつけておこう
}
    
