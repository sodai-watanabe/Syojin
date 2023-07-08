#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b;
    cin >> a >> b;

    if (abs(a-b) == 1) {
        if (a!=3 && a!=6) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}