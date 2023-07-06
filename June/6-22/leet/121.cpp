#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>maxPrice(n);
        maxPrice[n-1] = prices[n-1];

        for (int i=n-2; 0<=i; i--) {
            maxPrice[i] = max(maxPrice[i+1], prices[i]);
        }
        
        int maxPro = -1;
        for (int i=0; i<n; i++) {
            maxPro = max(maxPro, maxPrice[i]-prices[i]);
        }

        return maxPro;
    }
};