#include<bits/stdc++.h>
using namespace std;

int main () {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> a(N,0);

    for (int i=1; i<=N; i++) {
        if (i%X == 0) {
            a.at(i-1)+=1;
        }
        if (i%Y == 0) {
            a.at(i-1)+=2;
        }
    }

    for (int i=0; i<N; i++) {
        if (a.at(i) == 0) cout << "N" << endl;
        if (a.at(i) == 1) cout << "A" << endl;
        if (a.at(i) == 2) cout << "B" << endl;
        if (a.at(i) == 3) cout << "AB" << endl;
        // cout << a.at(i);
    }

    // cout << 2%2 ;
}