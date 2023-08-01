#include <bits/stdc++.h>
using namespace std;

int func (int n) {
    if (n == 0) return 0;

    int sum = 0;
    sum = func(n-1)+n;

    return sum;
}

int main () {
    int n;
    cin >> n;

    cout << func(n) << endl;
}