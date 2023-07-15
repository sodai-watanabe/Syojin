#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, P, Q;
    cin >> N >> P >> Q;

    int d = 100010;
    for (int i=0; i<N; i++) {
        int D;
        cin >> D;
        d = min (d, D);
    }

    int total = Q+d;
    cout << min(total,P);
}