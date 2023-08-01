#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> ans;
    for(int i=0; i<N-1; i++) {
        ans.push_back(A[i]+A[i+1]);
    }

    int prev=-1;
    unordered_map<int,int> m;
    for(int i=0;i<N-1;i++) {
       if(prev!=ans[i]) {
        prev=ans[i];
        m[ans[i]]++;
       } else {
        prev=-1;
       }
    }

    int maximum=-1;

    for(auto itr = m.begin(); itr!=m.end(); itr++) {
        maximum = max(maximum,itr->second);
    }
    return maximum;
}

int main () {
    int N;
    cin >> N;
    vector<int>A(N);

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    cout << solution(A);
}