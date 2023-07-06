#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long sum = 0;
    for(int i=0; i<64; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            unsigned long long two;
            two = pow(2, i);
            sum += two;
        }
    }
    cout << sum << endl;
}