#include<bits/stdc++.h>
using namespace std;

int main (){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > A(M, vector<int>(N));

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            A.at(i).at(j) = a;
        }
    }

    set<set<int> >aset;
    for(int i=0; i<N-1; i++){
        set<int> inset;
        inset.insert(A.at(0).at(i));
        inset.insert(A.at(0).at(i+1));
        aset.insert(inset);
    }

    for(int i=1; i<M; i++){
        for (int j=0; j<N-1; j++){
            set<int>bset;
            bset.insert(A.at(i).at(j));
            bset.insert(A.at(i).at(j+1));
            aset.insert(bset);
        }
    }

    int combi = (N*(N-1))/2;
    int ans = combi - aset.size();

    cout << ans << endl;
}















