#include<bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<string>S;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i==j) continue;

            string s1 = S.at(i)+S.at(j);
            int m = s1.length();
            bool frag = true;

            for (int k=0; k<m ; k++) {
                if (s1.at(k) != s1.at(m-1-k)) {
                    frag = false;
                    break;
                }
            }
            if (frag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;

}