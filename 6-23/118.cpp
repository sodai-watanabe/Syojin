#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // 返り値がvector<vector>で、そのままdpを返り値にするならvector<vector>で宣言しよう
        // dp[][]だとうまくかない
        vector<vector<int> >dp;

        for (int i=0; i<numRows; i++) {
            dp.push_back(vector<int>(i+1,1));
        }

        // vector<vector>で宣言しても、dp[][]で処理できるんだなあ
        for (int i=2; i<numRows; i++) {
            for (int j=1; j<i; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }

        return dp;
    }
};