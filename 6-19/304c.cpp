// BFS実装。何故かans<bool>が全てtrueになってしまう。解決に時間がかかり保留
// x, yの配列に入力されたx,yが代入されていないだけの凡ミス。解決した。
#include<bits/stdc++.h>
using namespace std;

int main () {
    int N, D;
    cin >> N >> D;

    vector<int>X(N); 
    vector<int>Y(N); 

    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
    }
    // cout << X[1];
    // 今回はグラフじゃなくて座標なので、二次元bool配列。
    vector<vector<bool> >list(N, vector<bool>(N));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int disq = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
            if (disq <= D*D) {
                list[i][j] = true;
            }
        }
    }

    vector<bool>ans(N, false);
    queue<int>que;


    ans.at(0) = true;
    que.push(0);

    while (!que.empty()) {
        int q = que.front();
        que.pop();

        for (int i=0; i<N; i++) {
            if (list[q][i] && !ans.at(i)) {
                ans.at(i) = true;
                que.push(i);
            }
        }
    }

    for (int i=0; i<N; i++) {
        if (ans.at(i)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}