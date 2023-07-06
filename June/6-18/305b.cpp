#include<bits/stdc++.h>
using namespace std;

int main () {
    char p, q;
    cin >> p >> q;

    int dist[7] = {0, 3, 4, 8, 9, 14, 23};

    int P = p - 'A' ;
    int Q = q - 'A' ;

    int ans = abs(dist[P] - dist[Q]);
    cout << ans << endl;


}