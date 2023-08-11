#include <bits/stdc++.h>
using namespace std;

int main () {
    int M,N;
    cin >> N >> M;

    vector<vector<int> >child(N+1);

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        child[b].push_back(a);
    }

    int count = 0;
    int ans = -1;

    for (int i=1; i<=N; i++) {
        if (child[i].size()==0) {
            count ++;
            ans = i;
        } 
    }

    if (count==1) {
        cout << ans;
    } else {
        cout << -1;
    } 
}