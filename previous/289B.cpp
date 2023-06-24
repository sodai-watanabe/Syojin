#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> re(N+1, false); 
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        re.at(a) = true;
    }

    vector<int> b;
    for(int i=0; i<N+1; i++){
        if(!re.at(i)){
            b.push_back(i);
        }
    }

    vector<int> ans(N);
    for(int i=0; i<N; i++){
        ans.at(i) = i+1;
    }

    for(int i=0; i<b.size()-1; i++){
        reverse(ans.begin() + b.at(i), ans.begin() + b.at(i+1));
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans.at(i) << ' ';
    }
}
