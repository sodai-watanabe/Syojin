#include <bits/stdc++.h>
using namespace std;

string S[7] = {"ACE","BDF","CEG","DFA","EGB","FAC","GBD"};

int main () {
    string s;
    cin >> s;

    for (auto st : S) {
        if (s == st) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}