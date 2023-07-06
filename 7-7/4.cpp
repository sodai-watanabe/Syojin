#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<int>A(n);
    vector<int>B(m);

    for (int i=0; i<n ; i++) {
        cin >> A.at(i);
    }
    for (int i=0; i<m ; i++) {
        cin >> B.at(i);
    }

    sort(A.begin(), A.end());

    for (int k=0; k<m; k++) {
        int key = B.at(k);
        int left = 0;
        int right = n;

        while (left != right) {
            int mid = (left+right)/2;

            if (A.at(mid)>key) right = mid;
            else left = mid+1;
        }
        cout << left << endl;
    }
}