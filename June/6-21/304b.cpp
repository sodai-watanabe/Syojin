#include<bits/stdc++.h>
using namespace std;

int main () {
    string zero = "00000000000000000000";
    string num;
    cin >> num;

    if (num.size() <= 3) {
        cout << num << endl;
        return 0;
    } else {
        int digit = num.size();
        string three = num.substr(0, 3);
        cout << three << zero.substr(0, digit-3) << endl;
    }
}