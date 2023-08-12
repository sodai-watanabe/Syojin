// Dango
// 速やかに解けた。8/11

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    string S;
    cin >> N >> S;

    int crr = 0;
    int ans = 0;

    bool frag = false;

    for (int i=0; i<S.size(); i++) {
        if (S[i]=='-') {
            frag = true;
            crr = 0;
        } else {
            crr++;
            ans = max(crr, ans);
        }
    }

    if (frag) {
        if (ans == 0) {
            cout << -1 << endl;
            return 0;
        }
        cout << ans << endl;
        return 0;
    } else {
        cout << -1 << endl;
        return 0;
    }
}