#include<bits/stdc++.h>
using namespace std;

char S[502][502];

int main () {
    int H,W;
    cin >> H >> W;

    for (int i=0; i<H; i++) {
        cin >> S[i];
    }
    int L = 505;
    int R = -1;
    int U = 505;
    int B = -1;

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (S[i][j] == '#') {
                L = min(j, L) ;
                R = max(j, R) ;
                U = min(i, U) ;
                B = max(i, B) ;
            }
        }
    }
    // cout << L << R << U << B;

    for (int i=U; i<=B; i++) {
        for (int j=L; j<=R; j++) {
            // cout << 1 ;
            if (S[i][j] == '.') {
                cout << i+1 << " " <<j+1 << endl;
            }
        }
    }
    return 0;
}