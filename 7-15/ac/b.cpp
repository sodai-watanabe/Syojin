// https://atcoder.jp/contests/abc310/tasks/abc310_b
// これ、sampleは通るのに実際はテストケースのsampleは通っていないことになっている。原因不明。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    vector<int>P(N);
    vector<set<int> >F(N);

    for (int i=0; i<N; i++) {
        int C;
        cin >> P[i] >> C;
        for (int j=0; j<C; j++) {
            int f;
            cin >> f;
            F[i].insert(f);
        }
    }

    bool ans = false;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i==j) continue;

            if (P[i]>=P[j]) {
                bool inc = true;
                for (auto fi : F[i]) {
                    if (!F[j].count(fi)) {
                        inc = false;
                    }
                }

                if (inc) {
                    bool jwin;
                    for (auto fj : F[j]) {
                        if(!F[i].count(fj)) jwin = true;
                    }
                    if (jwin || P[i]>P[j]) ans = true;
                }
            }
        }
    }

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}