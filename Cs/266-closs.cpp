// 幾何問題　要復習　9/20
// 問題：座標が4点与えられる。4点からなる四角形が全ての角が180度未満であるかどうかを判定せよ。(凸判定)
// 方針：各頂点に対して、ベクトルの外積を用いて180度との大小を判定。
// 教訓：180度との大小判定 → 頂点から出る2ベクトルを用意し、外積が正ならば0~180度。

#include <bits/stdc++.h>
using namespace std;

int main () {
    // かく頂点座標管理
    vector<pair<double,double> >P(4);
    for (int i=0; i<4; i++) {
        double x,y;
        cin >> x >> y;
        pair<double,double>p(x,y);
        P[i]=p;
    }

    // 各頂点を一つずつ見ていく
    for (int v=0; v<4; v++) {

        // 教訓：配列で一つずつ見ていき、見ている頂点とそれ以外頂点の表し方
        pair<int,int>A=P[v];       // 見ている頂点
        pair<int,int>B=P[(v+1)%4]; // 右側の頂点
        pair<int,int>D=P[(v+3)%4]; // 左側の頂点

        pair<int,int>AB(B.first-A.first,B.second-A.second); // 右側のベクトル
        pair<int,int>AD(D.first-A.first,D.second-A.second); // 左側のベクトル

        // 外積計算AB×AD
        int closs = AB.first*AD.second - AD.first*AB.second;

        if (closs<0) {
            cout << "No" << endl;
            return 0;
        }      
    }

    cout << "Yes" << endl;
    return 0;
}
 