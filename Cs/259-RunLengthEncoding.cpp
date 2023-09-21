// Run length encoding 要復習 9/21
// 問題：S,Tが与えられる。S内の同種文字連続箇所に同種文字を挿入する操作を任意の回数行うことで、SをTにすることができるかを判定せよ。
// ex) aaaabbcddd → (a,4),(b,2),(c,1),(d,3)   文字種類とその数を順に列挙した表記がRleという。
// 教訓：文字列内で同種文字の連続判定 → S[i]==S[i-1]

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string S,T;
    cin >> S >> T;
    vector<pair<char,int> >sp;
    vector<pair<char,int> >tp;
    int Ssize = S.size();
    int Tsize = T.size();

    // 現在見ている文字
    char nows = ' ';
    // 現在見ている文字の連続数
    int sstreak = 1;
    // Sを2文字目から見てRleを作る。
    for (int i=1; i<Ssize; i++) {
        
        // 見ている文字が連続していたならばstreakを加算。
        if (S[i-1]==S[i]) {
            sstreak++;
        // 連続していない、一つ前の文字と種類が異なる場合は(char,streak)を追加しstreakを1にリセット。
        } else {
            pair<char,int>p(S[i-1],sstreak);
            sp.push_back(p);
            sstreak=1;
        }
        // 最後の文字は連続していようがなかろうが終了なので(char,streak)を追加。
        if (i==Ssize-1) {
            pair<char,int>p(S[i],sstreak);
            sp.push_back(p);
        }
    }

    // Tも同様にしてRleを作る。
    char nowt = ' ';
    int tstreak = 1;
    for (int i=1; i<Tsize; i++) {
        
        if (T[i-1]==T[i]) {
            tstreak++;
        } else {
            pair<char,int>p(T[i-1],tstreak);
            tp.push_back(p);
            // cout << p.first << ' ' << p.second;
            tstreak=1;
        }

        if (i==Tsize-1) {
            pair<char,int>p(T[i],tstreak);
            tp.push_back(p);
            // cout << p.first << ' ' << p.second;
        }
    }
    int Ns = sp.size();
    int Nt = tp.size();

    // Rleの要素数が同じでないとSからTを作ることは不可能。
    if (Ns != Nt) {
        cout << "No" << endl;
        return 0;
    }
    // S,Tの文字種類と順番は一致する必要がある。また操作ができるのはSの文字が2連続以上の時のみ。
    // S,Tの同種文字ではSよりTの方が大きい必要あり。
    for (int i=0; i<Ns; i++) {
        if (tp[i].first!=sp[i].first || tp[i].second<sp[i].second || (tp[i].second>sp[i].second && sp[i].second==1)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}