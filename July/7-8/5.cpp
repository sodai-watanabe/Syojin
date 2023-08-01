// https://algo-method.com/tasks/381
// 二変数不等式で２重ループの回避
// 教訓：二変数のときは、片方を固定して一変数で考える。forの中で二分探索。

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long N, K;
    cin >> N >> K;

    vector<long long>A;

    for (int i=0; i<N; i++) {
        long long a;
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    long long ans = 0;


    for (int i=0; i<N; i++) {

        long long left = 0;
        long long right = N;
        long long key = K-A[i];   // 添え字iのAを固定して考える

        while (left!=right) {
            long long mid = (left+right)/2;   // midはwhile内でその都度再宣言
            if (A[mid]>=key) right = mid;     // 「以上」を求めるのでupper_boundの条件でrightとleftを更新
            else left = mid+1;   // 左から幅を狭める
        }

        ans += N-left;    // 「以上」の個数をansに加算
    }

    cout << ans << endl;
}