// 復習
#include <bits/stdc++.h>
using namespace std;

string binary(int N) {
    string ans;
    while (N!=0) {
        if (N%2==1) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
        N/=2;
    }
    return ans;
}

int main() {
    // Implement your solution here
    int N = 32;
    
    string ans = binary(N);

    int count = 0;
    bool frag;
    int max = 0;
    
    for (int i=0; i<ans.size(); i++) {
        if (ans[i]=='1') {
            frag = true;
            if (count > max) {
                max = count;
            }
            count = 0;
        } else {
            if (frag) {
                count++;
            }
        }
    }
    cout << ans << " " << max;
}