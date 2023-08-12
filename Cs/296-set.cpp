// Gap exist
// A[i]-A[j]=Xなるi,jペアは存在するかを判定する。
// 教訓：2変数問題は移項して1変数として解く。
// 教訓：存在判定はsetが便利

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, X;
    cin >> N >> X;

    set<signed long long>S1;
    set<signed long long>S2;
    for (int i=0; i<N; i++) {
        signed long long a;
        cin >> a;

        S1.insert(a);
        S2.insert(a+X);
    }

    for (auto a : S1) {
        if (S2.count(a)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}