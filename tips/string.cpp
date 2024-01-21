// 1/20 ABC337-B
// method:: string(4,'A') → AAAA  連続文字列
// method:: count(S.begin(),S.end(),'A') → 文字列Sに含まれる'A'の数

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string S;
    cin >> S;
    string c = "";

    int l = S.length();

    // char now = 'X';

    // for (int i=0; i<l; i++) {
    //     if (S[i]==now) continue;
    //     now=S[i];
    //     c.push_back(now);
    // }

    // if (c == "ABC" ||c == "A" || c == "B" ||c == "C" || c == "AB" ||c == "BC" ||c == "AC") {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }

    // cout << c << endl;

    cout << string(4,'A') << endl;   // AAAA
    cout << count(S.begin(),S.end(),'A');  // S="ANPANMAN"の時,3が出力
}