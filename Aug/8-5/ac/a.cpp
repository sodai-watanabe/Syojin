#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    if (N==1) {
        cout << 0;
        return 0;
    }

    vector<int>P(N);

    for (int i=0; i<N; i++) {
        cin >> P[i];
    }

    sort(P.begin()+1, P.end());

    int gap = P[N-1]-P[0];
    if (gap<0) {
        cout << 0;
    } else {
        cout << gap+1;
    }
}