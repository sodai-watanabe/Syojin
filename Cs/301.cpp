// ch@ku@ai,choku@@i →Yes
// aoki,@ok@→No
// @は"atcoder"に含まれる文字に置き換えられる
// 教訓：文字リストで文字数を管理。'a'→cs[0],'b'→cs[1]...ならばcs[s[i]-'a']とする。
#include <bits/stdc++.h>
using namespace std;

int main () {
    string s,t;
    cin >> s >> t;

    // 文字数管理リスト  aが~個,bが~個
    vector<int>cs(27,0); 
    vector<int>ct(27,0);

    // '@'はzの次に入れていおく。'@'以外は文字番号indexの値をインクリメント
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='@') {
            cs[26]++;
        } else {
            cs[s[i]-'a']++;
        }

        if (t[i]=='@') {
            ct[26]++;
        } else {
            ct[t[i]-'a']++;
        }
    }

    string A = "atcoder";

    // "atcoder"に含まれる文字はどこにあるかを管理する配列。特に変更はしないもの。
    vector<bool>inA(26,false);

    // 小文字のみならinA[c-'a']することで、char→intへ変換できる。
    for (char c : A) {
        inA[c-'a']=true;
    }


    //　"atcoder"にない文字の文字数が異なる場合→どうしようもない
    for (int i=0; i<26; i++) {  
        if (!inA[i]) {
            if (cs[i]!=ct[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // 入力文字列sとtでそれぞれの文字の文字数が異なる場合の処理
    for (int i=0; i<26; i++) {
        if (inA[i]) { // まずは"atcoder"に含む文字でないと置き換えができない。
            if (cs[i]>ct[i]) {
                ct[26]-=cs[i]-ct[i];  // sに含まれる文字数が大きい場合→tの@を差分消費して同じ数にする。
            } else if (cs[i]<ct[i]) {
                cs[26]-=ct[i]-cs[i];  // // tに含まれる文字数が大きい場合→sの@を差分消費して同じ数にする。
            }
        }
    }

    // @が0以上ならセーフ、負になっていたら@が足りていないのでアウト
    if (cs[26]<0 || ct[26]<0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}