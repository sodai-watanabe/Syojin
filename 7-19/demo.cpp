#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    int N = A.size();
    sort(A.begin(),A.end());

    set<int>s;

    for (int i=0; i<N; i++) {
        s.insert(A[i]);
    }

    for (auto a : s) {
        cout << a << " ";
    }

    for (int i=1; i<N; i++) {
        if (!s.count(i)) {
            return i;
        }
    }
}

int main () {
    int N;
    cin >> N;
    vector<int>A(N);
    // sort(A.begin(),A.end());
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // cout << A[0] << endl;

    cout << solution(A);
    // solution(A);
}