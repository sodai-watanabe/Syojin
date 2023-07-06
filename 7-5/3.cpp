// https://algo-method.com/tasks/370
// lower_bound
// 疑問：右から狭めるパターンはなぜ無限ループになるのか
// ans:基本は左から狭めうよう。lowerかupperは(while内の不等式の決め方)配列の図を書くとわかりやすい。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;

    vector<int>A(n);
    vector<int>B(m);

    for (int i=0; i<n ; i++) {
        cin >> A.at(i);
    }
    for (int i=0; i<m ; i++) {
        cin >> B.at(i);
    }

    // sort(B.begin(), B.end());
    for (int k=0; k<m; k++) {
        int key = B.at(k);

        double left = 0;
        double right = n-1;

        while (right!=left) {   // 左から狭めていくパターン
            int mid = left + (right - left)/2;   // (right-left)/2が必ず整数とは限らないが、intにしておけば切り捨て
            if (A.at(mid)>=key) right = mid;
            else left = mid+1;   // A.at(mid)<keyの時(=なし)は、+1しても超えないので問題ない
        }
        // while (right!=left) {                 //　右から狭めていくパターン。これだと無限ループになるがその理由がわからない。
        //     int mid = left + (right - left)/2;   
        //     if (A.at(mid)<=key) left = mid;
        //     else right = mid-1;
        // }

        int ans = right;
        cout << ans << endl;
    }
}