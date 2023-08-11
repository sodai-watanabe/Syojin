// テストケース一つだけWAになる。
// 未解決

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    vector<string>S(N);

    for (int i=0; i<N; i++) {
        cin >> S[i];
    }

    vector<pair<int,int> >P;

    for (int i=0; i<=N-9; i++) {
        for (int j=0; j<=M-9; j++) {
            bool frag = true;

            for (int k=i; k<i+9; k++) {
                for (int l=j; l<j+9; l++) {
                    if (k<i+3 && l<j+3) {
                        if (S[k][l]!='#') frag = false;
                    }
                    if (k>=i+6 && l>=j+6) {
                        if (S[k][l]!='#') frag = false;
                    }

                    if ((k==i+3 && l<=j+3) && (k<=i+3 && l==j+3)) {
                        if (S[k][l]=='#') frag = false;
                    }
                    if ((k==i+5 && j+5<=l) && (i+5<=k && l==j+5)) {
                        if (S[k][l]=='#') frag = false;
                    }
                }
            }

            if (frag) {
                pair<int,int>p = make_pair(i+1,j+1);
                P.push_back(p);
            }
        }
    }

    sort(P.begin(), P.end());
    for (auto p : P) {
        cout << p.first << ' ' << p.second << endl;
    }
}