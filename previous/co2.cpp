#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    set<int> single_A;
    multiset<int> all_A;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        single_A.insert(a);
        all_A.insert(a);
    }

    int ans = 0;
    for(int n : single_A){
        int co = all_A.count(n);
        ans += co/2;
    }

    cout << ans;
}