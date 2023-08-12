#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<vector<int> >A(N);

    for (int i=0; i<N; i++) {
        int c; 
        cin >> c;

        for (int j=0; j<c; j++) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    int X;
    cin >> X;

    vector<pair<int, int> >insi;
    int minsize = 40;

    for (int i=0; i<N; i++) {
        for (auto v : A[i]) {
            if (v == X) {
                pair<int,int>p = make_pair(i,A[i].size());
                insi.push_back(p);
                minsize = min(minsize, p.second);
            }
        }
    }

    int num =0;

    for (auto p : insi) {
        if (p.second == minsize) {
            num++;
        }
    }
    cout << num << endl;

    for (auto p : insi) {
        if (p.second == minsize) {
            cout << p.first+1 << ' ';
        }
    }
}
