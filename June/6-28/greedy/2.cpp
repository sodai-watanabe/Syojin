// greedy
// 実装力というよりは、設計を正しく行うことが大事

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int ans = 0;

    while (n != 0) {
        if (n%2 == 0) {
            n/=2;
        } else {
            n-=1;
        }
        ans++;
    }
    cout << ans << endl;
}