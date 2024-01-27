// 1/27 ABC-A
// https://atcoder.jp/contests/abc338/editorial/9159
// 大文字判定→isupper(char)が0以外を返す
// boolにしたければ明示するべき→bool(isupper(char))


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string S;
    cin >> S;

    if (!isupper(S[0])) {
        cout << "No" << endl;
        return 0;
    }

    for (int i=1; i<S.length(); i++) {
        if (isupper(S[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;

    


}