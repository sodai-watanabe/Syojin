// DP　
// 三項間数列のような解き方。
//  dp[i] = dp[i-1] + 2*dp[i-2];としないように。理由は、二つ前のマスからの行き方は、2を使う1通りのみだから。1+1をすると、一つ前のマスから来ていることになる。
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) {
            return n;
        }

        vector<int>dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        // 注意：dp[i] = dp[i-1] + 2*dp[i-2];は数え過ぎ
        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];       
    }
};