// recursion
// aからbまでの和

#include <bits/stdc++.h>
using namespace std;

int func (int a, int b) {   // a~bまでの和をとる関数
    if (a > b) return 0;    // 第二引数bがaより小さくなったら終了

    return func(a, b-1)+b;  // a~bの和は、a~b-1の和にbを足したもの。
}

int main () {
    int a, b;
    cin >> a >> b;
    int ans = func(a, b);

    cout << ans << endl;
}