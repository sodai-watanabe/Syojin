// binary search
// https://algo-method.com/tasks/368
// leftを左の範囲外に,rightを右の範囲外に初期値で定義。
// 中点midを定義。条件を見て、適宜端点を更新。
// right-left>1の間は更新し続ける。

#include <iostream>
using namespace std;

double f(double x) {
    return x*(x*(x+1)+2)+3;
}

int main () {
    double N; cin >> N;

    double left = -1;
    double right = 100;

    while (right - left > 1e-4) {
        double mid = left + (right - left)/2;
        if (f(mid) < N) left = mid;
        else right = mid;
    }

    double ans = right;

    cout << ans << endl;
}