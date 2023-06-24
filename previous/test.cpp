#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    vector<pair<int, int> > C;

    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<M; i++){
        cin >> B[i];
    }
    for(int i=0; i<N; i++){
        C.emplace_back(A.at(i), i);
    }
    for(int i=0; i<M; i++){
        C.emplace_back(B.at(i), i+N);
    }

    sort(C.begin(), C.end());

    vector<int> ai(N);
    vector<int> bi(M);
    for(int i=0; i<N+M; i++){
        int j = C.at(i).second;
        if(j < N){
            ai.at(j) = i + 1;
        } else {
            bi.at(j-N) = i + 1;
        }
    }

    for(int c : ai) cout << c << ' ';
    cout << endl;
    for(int c : bi) cout << c << ' ';
}