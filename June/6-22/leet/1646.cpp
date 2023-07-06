#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        int nums[n+1];
        nums[0] = 0;
        if (n <= 1) {
            return n;
        }
        nums[1] = 1;

        int maximum = -1;

        for (int i=2; i<=n; i++) {
            if (i%2 == 0) {
                nums[i] = nums[i/2];
            } else {
                nums[i] = nums[(i-1)/2] + nums[(i-1)/2 + 1];
            }

            maximum = max(maximum, nums[i]);
        }

        return maximum;
    }
};