// 順列全探索next_permutation
// 問題：長さMの文字列がN個入力。隣同士が1文字だけ異なる文字列になる並べ方が存在するか判定せよ。
// 方針：並べ方を全通り試す。
// 教訓：next_permutationを呼ぶ前に必ず配列をsortする。

#include <bits/stdc++.h>
using namespace std;
int N,M;

// 引数の文字列型配列が、隣同士が1文字だけ異なる文字列になっているかを判定
bool judge (vector<string>S) {
    
    // 配列の隣同士を見る
    for (int i=0; i<N-1; i++) {

        int deff = 0;  // 二つの要素(文字列)の、異なる文字数

        // 2要素の文字を一文字ずつ比較
        for (int j=0; j<M; j++) {
            if (S[i][j]!=S[i+1][j]) { //　もし文字が異なったらdeffを加算
                deff++;
            }
        }
        if (deff!=1) return false;    // 異なる文字数が1文字でない時はng
    }

    return true;
} 

int main () {
    cin >> N >> M;
    vector<string>S(N);
    for (int i=0; i<N; i++) {
        cin >> S[i];
    }

    // next_permutationを呼ぶ前には必ずsortする。
    sort(S.begin(),S.end());

    // do内は処理、while内は条件。
    do {
        if (judge(S)) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(S.begin(),S.end()));   // 配列要素の並べ方を全通り試してくれる

    cout << "No" << endl;
    return 0;
}