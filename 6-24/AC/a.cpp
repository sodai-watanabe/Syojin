#include<bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int week=0;
        for (int j=0; j<7; j++) {
            int a;
            cin >> a;
            week += a;
        }
        cout << week << " ";
    }
}