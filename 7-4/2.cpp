// binary search
// https://algo-method.com/tasks/367
// ただ単に、配列で並んでいる数字の探索ではない
// ある短調増加関数の結果を探索する。その関数は、mainとは別で切り離したほうが良い。
// 躓いた点：異なる型同士で演算してしまった。1e-4を1e4としてしまっていた。

#include <iostream>
using namespace std;

double f (double n, double x) {    // 5年後の資産を算出する関数
    for (int i=0; i<5; i++) {      // 注意：doubleとintなど、異なる型同士の演算はできない！！！
        n++;
        n*=x;
    }
    return n+1;
}

int main () {
    double n;
    double m;
    cin >> n >> m;

    double left = -1;     // 両端の初期値は範囲外にしておき、更新されるように
    double right = 1000;

    while (right - left > 1e-4) {         // 注意:1e-4を1e4にとしていて躓いていた。eは10の何乗かの意味
        double mid = left + (right - left)/2;
        if (f(n, mid)<m) {
            left = mid;
        } else {
            right = mid;
        } 
    }

    double ans = right;

    cout << ans << endl;
}