#include <bits/stdc++.h>
using namespace std;

int main () {
    int N,M;
    cin >> N >> M;

    string S;
    cin >> S;

    vector<int>co(N);

    for (int i=0; i<N; i++) {
        cin >> co[i];
    }

    vector<vector<int> >A(M);

    for (int i=0; i<N; i++) {
        A[co[i]-1].push_back(i);
    }


    // shift
    string ans = S;
    for (int i=0; i<M; i++) {
        int l = A[i].size();  

        for (int j=0; j<l; j++) {
            ans[A[i][(j+1)%l]] = S[A[i][j]] ;
        } 
    }

    cout << ans << endl;   
}