// ACはできていないが、答えはあっている。おそらく不具合。 8/20
// これは割と愚直にやるだけ。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N,M;
    cin >> N >> M;
    vector<string>S;
    vector<pair<int, int> >ans;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            bool frag = true;
            
            for (int k=0; k<3; k++) {  // 角の9こが#かどうか
                for (int l=0; l<3; l++) {
                    if(S[i+k][j+l]!='#') {
                        frag = false;
                        break;
                    } 
                    if(S[i+6+k][j+6+l]!='#') {
                        frag = false;
                        break;
                    } 
                }
            }
            
            for (int k=0; k<4; k++) {  // 周りの横列判定
                if (S[i+3][j+k]!='.') {
                    frag = false;
                    break;
                }
                if (S[i+5][j+8-k]!='.') {
                    frag = false;
                    break;
                }
            }
            for (int k=0; k<3; k++) {  // 周りの縦列判定
                if (S[i+k][j+3]!='.') {
                    frag = false;
                    break;
                }
                if (S[i+8-k][j+5]!='.') {
                    frag = false;
                    break;
                }
            }
            if (frag) {
                pair<int,int>p = make_pair(i,j);
                ans.push_back(p);
            }
        }
    }

    sort (ans.begin(),ans.end());
    for (auto p : ans) {
        cout << p.first+1<< ' ' << p.second+1 << endl;
    }

}