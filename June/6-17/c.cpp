#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int> > A(N);
    vector<pair<int, int> > P;

    for (int i = 0; i < 3 * N; i++) {
        int a;
        cin >> a;
        A.at(a - 1).push_back(i + 1);
    }

    for (int i = 0; i < N; i++) {
        P.emplace_back( A.at(i).at(1), i + 1 );
    }

    sort(P.begin(), P.end());

    for (auto p : P) {
        cout << p.second << " ";
    }

    return 0;
}
