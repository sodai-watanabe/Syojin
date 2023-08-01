// https://algo-method.com/tasks/399
// 配列の値と添え字(番目)の両方の情報を保持したい問題
// 教訓：同じ配列を二つ用意して、片方sortする。元の配列要素V[k]がsort済み配列Wで何番目にあるのかを二分探索。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int>W;
    vector<int>V;

    for (int i=0; i<n; i++) {
        int w;
        cin >> w;
        W.push_back(w);       // 同じ配列WとVを用意する
        V.push_back(w);
    }

    sort(W.begin(), W.end());  // 配列Wを値の小さい順にsort

    for (int k=0; k<n; k++) {  // 元の配列要素V[k]が全体の何番目に小さいのかを探索
        int key = V[k];
        int left=0;
        int right= n-1;

        while (left!=right) {  // 二分探索
            int mid = (left+right)/2;
            if (W[mid]<key) left = mid+1;
            else if (W[mid]>=key) right = mid;            
        }

        cout << left << endl;
    }
}