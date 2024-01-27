// 1/27 ABC-B
// 英小文字数字変換 → int c = S[i]-'a';
// 数字英小文字変換 → char ansc = 'a'+ans;
// char-loop可能  → for (char c = 'b'; c <= 'z'; ++c) 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string S;
    cin >> S;

    vector<int>ch(26,0);

    for (int i=0; i<S.length(); i++) {
        int c = S[i]-'a';
        ch[c]++;
    }

    int maxnum = -1;
    int now = 0;
    int ans = 0;
    for (int i=0; i<26; i++) {
        if (ch[i]>maxnum) {
            maxnum = ch[i];
            ans = i;
        }
    }

    char ansc = 'a'+ans;
    cout << ansc << endl;

}