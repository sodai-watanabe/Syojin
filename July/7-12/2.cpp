// https://algo-method.com/tasks/440
// 選択sort
// 配列要素一つづつ見ていき、自分以降の要素の中で最小のものと自分自身をswapする。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    for (int k=0; k<N-1; k++) {  // 配列要素一つづつ見ていく
        auto min_itr = min_element(A.begin()+k, A.end());   //自分以降の要素の中で最小のもののitr

        swap(A[k], *min_itr);   // 最小の要素と、自分自身をswap
        for (auto a : A) {
            cout << a << " ";
        }
        cout << endl;
    }

}