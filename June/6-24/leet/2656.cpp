// 一応greedy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int numMax = -1;
        for (auto n : nums) {
            numMax = max(numMax, n);
        }
        for (int i=0; i<k; i++) {
            numMax+=numMax+1;
        }

        return numMax;
    }
};