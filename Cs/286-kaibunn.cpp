// 回文判定  8/14 重要
// 文字列Sに対して、rotateと文字の置き換えによって回文にするまでにかかる操作の最小値を答える。
// 教訓：rotateと文字の置き換えは独立。順番は関係ないのでrotateを全て試し、それぞれの文字列に対して必要な分だけ置き換えするように。
// 教訓：文字列のrotate → rotate(T.begin(), T.begin()+i, T.end())で、abcdからbcdaになる
// 教訓：文字列の両脇から中心へ攻めたい → for (int l=0, r=N-1; l<r; l++,r--){}
// 教訓：1e18 → 10^18
// 教訓:rotate問題 → originalのcopyを用意。copyを変更してrotateする。基本的にoriginalはいじらない。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int N;
    ll A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    ll ans = 1e18;  // 10^18。最小値問題なので大きい数で初期化。

    // まずrotateについて全ての通りを見る。
    for (int i=0; i<N; i++) {
        string T = S; // copyを用意
        rotate(T.begin(), T.begin()+i, T.end());
        ll now = A*i;  // 答えはrotateコストで初期化

        // rotateによってできた文字列に対して、回文判定する。
        for (int l=0, r=N-1; l<r; l++,r--) { // 両脇から中心へ、2文字を比べていく。
            if (T[r]!=T[l]) { // 2文字が異なる場合は回文にするために文字を片方置き換える。
                now += B; // 置き換えコスト加算。
            }
        }
        ans = min(now, ans); // ansと現在試している方法のコストを比較。今までの最小を採用。
    }
    cout << ans << endl;
}