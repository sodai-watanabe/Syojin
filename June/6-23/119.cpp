#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 
        vector<vector<int> >dp;
        
        for (int i=0; i<=rowIndex; i++) {
            dp.push_back(vector<int>(i+1,1));
        }

        for (int i=0; i<=rowIndex; i++) {
            // j<iとする。
            for (int j=1; j<i; j++) {
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[rowIndex];
    }
};