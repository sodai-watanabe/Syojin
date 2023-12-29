// 悪くない。　9/19,12/29⭕️
// これと言った教訓が思いつかない。ただ模範解答はもう少しスマートなので次はそちらでできるように
// 考察ゲーム

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    set<int>st;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        st.insert(A[i]);
    }

    int index = 1;
    int l = st.size();
    map<int,int>sp;

    for (auto s : st) {
        pair<int,int>p(s,index);
        sp.insert(p);
        index++;
    }

    vector<int>K(N,0);

    for (int i=0; i<N; i++) {
        int k = l-sp[A[i]];
        K[k]++;
    }

    for (auto k : K) {
        cout << k << endl;
    }
}