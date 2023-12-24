// slot 要復習 9/24, 12/22
// 問題：N個のスロットが与えられ、各スロットは0~9の数字が一つづつ書いてある。スロットを揃えるためにかかる時間の最小値を求めよ。
// 問題：一度に押せるのは1つのスロットのみ。
// 方針：0~9の数字nに着目。各スロットのnのindexに注目し、nの分布配列を作る。
// 方針：基本はindexが最大のものがnのかかる時間だが、おなじindexが複数存在する場合は、1周末ので+10する、というのを一般化して表現。
// 方針：各nのかかる時間の最小値が、全体的な答え(揃うまでにかかる時間の最小値)になる。
// 教訓：intからcharに変換 → char c = '0'+n;
// 教訓：indexに注目 → 分布配列を作成

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    // N個のスロット。
    int N;
    cin >> N;
    // スロットの文字列を管理。
    vector<string>S(N);

    for(int i=0; i<N; i++) {
        cin >> S[i];
    }

    int ans = 1e8;

    for (int n=0; n<10; n++) {
        // intをcharに変換。
        char c = '0'+n;

        // nが各レーンのどのindexかの分布。
        vector<int>num(10,0);

        // Sを一文字ずつ探索。
        for (int i=0; i<N; i++) {
            for (int j=0; j<10; j++) {
                if (S[i][j]==c) {
                    // nがあったらn分布に加算。
                    num[j]++;
                }
            }
        }

        int now = -1;
        // index分布を探索。
        for (int i=0; i<10; i++) {
            // 考察より、indexの分布が1増えると10秒加算。
            int t = i + 10*(num[i]-1);
            // より長く時間がかかるものが現在の時間になる。
            now = max(now,t);
        }

        // 0~9において、最も早く揃うものが最終的な答えになる。
        ans = min(ans,now);

    }

    cout << ans << endl;
}