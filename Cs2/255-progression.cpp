// 等差数列
// 問題：初項A,公差D,項数Nの等差数列がある。Xとの差が一番小さい項の差を出力せよ。
// 方針：まず公差D<0の場合は大変扱いづらいのでD>0となるように等差数列の反転を行う。その上で、Xが数列の範囲外か範囲内で場合分けする。
// 教訓：等差数列の公差が負は扱いづらい → 末項を初項に、公差の符号を反転させて正にすることで反転できる。
// 教訓：A=3,D=-4,N=4の場合  {3,-1,-5}→{-5,-1,3} になる。項の集合自体は変えずに公差を正にする。
// 教訓：等差数列の反転 → A→A+D*(N-1),D(<0)→-D(>0)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll X,A,D,N;
    cin >> X >> A >> D >> N;
    ll X2 = X-A;
    ll fi = D*(N-1);

    // Dの値で場合分けをした。ただ、場合分けが複雑でかなりミスが増えそう。
    // Dを正に揃えて、同じ性質の等差数列に直してから同じ条件で処理するのがミスが少ない。
    if (D==0) {
        cout << abs(X-A) << endl;
    }

    if (D>0) {
        if (X2>0) {
            if (X2<fi) {
                cout << min(X2%D,D-X2%D) <<endl;
            } else {
                cout << X2-fi << endl;
            }
        } else {
            cout << abs(X2) << endl;
        }
    }

    if (D<0) {
        if (X2>=0) {
            cout << X2 << endl;
        } else {
            if (abs(X2)<abs(fi)) {
                cout << min(abs(X2)%abs(D),abs(D)-abs(X2)%abs(D)) << endl;
            } else {
                cout << abs(fi-X2) << endl;
            }
        }
    }

    return 0;
}