// 辞書順で一つ前の列を出力 9/18
// 教訓：prev_permutation(P.begin(),P.end()) → 辞書順で一つ前のものがPに格納される。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int>P(N);
    for (int i=0; i<N; i++) {
        cin >> P[i];
    }

    prev_permutation(P.begin(),P.end());

    for (auto p : P) {
        cout << p << ' ';
    }

    return 0;
}

// お試し
