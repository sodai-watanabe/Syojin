// ここでは全て正解なのに、提出するとREが出るの何故だろう
// 本当にわからない

#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1, -1, 1, 1};
int dy[4]={-1, 1, 1, -1};

int main () {
    int H, W;
    cin >> H >> W;

    vector<string>C(H);

    for (int i=0; i<H; i++) {
        cin >> C[i];
    }

    int N = min(H, W);

    vector<int>ans(N,0);

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (C[i][j]!='#') continue;

            int cnt = 0;
            for (int n=0; n<4; n++) {
                int t = i+dy[n];
                int s = j+dx[n];

                if (C[t][s]=='#') cnt++;
            }
            if (cnt == 4) {
                int n = 2;
                while (true) {
                    if (C[i+n][j+n]!='#') break;
                    if (C[i+n][j-n]!='#') break;
                    if (C[i-n][j+n]!='#') break;
                    if (C[i-n][j-n]!='#') break;

                    n++;
                }
                ans[n-1]++;
            }
        }
    }

    for (int i=1; i<=N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}