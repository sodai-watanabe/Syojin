// 要復習8/13
// 8/24 coをそれぞれshiftした新しい2次元配列を作ったらTEL.計算量的には模範回答と変わらない気がしているので原因不明
// Rotate Colored Subsequence
// 文字列とその文字のcolor(int)が与えられる。
// 同じ色の文字で、右へ一つshiftして得られる文字列を答える。
// 教訓：配列(文字列)を右へn個shift → ①同じ配列(文字列)のcopyを用意。②copy[(i+n)%size]=A[i];
// 教訓：配列shift→copy[(i+n)%size]=A[i]と配列長で割った余りを用いることで、一つずらしつつ配列外参照時には配列の初めにrotateするようにできる。


#include <bits/stdc++.h>
using namespace std;

int main () {
    int N,M;
    cin >> N >> M;

    string S;
    cin >> S;

    vector<int>co(N);

    for (int i=0; i<N; i++) {
        cin >> co[i];
    }

    // colorごとに文字のindexを管理する配列
    vector<vector<int> >A(M);

    // colorごとにindexを入れる
    for (int i=0; i<N; i++) {
        A[co[i]-1].push_back(i);
    }


    string ans = S;  // copyの文字列。これを変更して最終的な答えとするもの。

    // shift
    for (int i=0; i<M; i++) { // Aを順番に見ていく。

        // color(i)のcharの数
        int l = A[i].size();  

        // color(i)も文字だけ見て、右へ一つshift。(重要：%lで配列外参照のケア)
        for (int j=0; j<l; j++) {
            ans[A[i][(j+1)%l]] = S[A[i][j]] ; // ansのどこかに、元の文字列Sの文字を入れていく。
        } 
    }

    cout << ans << endl;   
}