#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int total[1010];
int dp[1010];

    int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         total[0] = 0;
//         total[1] = cost[0];

//         for (int i=2; i<cost.size(); i++) {
//             total[i] = min(total[i-1]+cost[i-1], total[i-2]+cost[i-2]);
//         }
//         int ans1 = min(total[n-1]+cost[n-1], total[n-2]+cost[n-2]);

//         total[0] = 0;
//         total[1] = 0;
//         total[2] = cost[1];

//         for (int i=3; i<cost.size(); i++) {
//             total[i] = min(total[i-1]+cost[i-1], total[i-2]+cost[i-2]);
//         }
//         int ans2 = min(total[n-1]+cost[n-1], total[n-2]+cost[n-2]);

//         return min(ans1, ans2);




// ----------------------------best answer-------------------------------
        // dp[1] = cost[1]+dp[0]出ないことに注意。
        // おそらく正確には、dp[1] = min(cost[1]+dp[0],cost[1])
        // index0から1stepで来た場合と、元からindex1からスタートする場合で小さいほうを取りたいが、どの場合も後者の方が小さいのでminは書かない。
        int n = cost.size();
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i=2; i<n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        // topの1つ下から、または2つ下から辿り着く場合があり、答えはそれらの小さい方
        int ans = min(dp[n-2],dp[n-1]);

        return ans;
    }
};