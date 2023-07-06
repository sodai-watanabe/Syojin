#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 配列の要素数はn+1に注意
           vector<int>dp(n+1,0);
           dp[0] = 1;
           dp[1] = 1;

           if (n == 1) {
            return 1;
           } else {
                for (int i=2; i<=n; i++) {
                 dp[i] = dp[i-1] + dp[i-2];
                }
                return dp[n];
           }
    }
};