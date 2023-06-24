#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for (int i=0; i<=n; i++) {
            int num = i;
            int sum = 0;
            if (num == 0 || num == 1) {
                ans.push_back(num);
                continue;
            }

            // 2進数表記を求めるとき,0になるまで2で割りますね。割った時のあまり(0or1)がそのまま2進数表記になる。
            while (num!=0) {
                // sumを足し合わせてから、numを2で割る。順番だいじ。
                sum += num%2;
                num/=2;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};