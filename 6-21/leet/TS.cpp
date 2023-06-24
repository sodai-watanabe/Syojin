#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            for (int j=1; i<j && j<n; j++) {
                if (nums.at(i) + nums.at(j) == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
int main() {
    // テストコードなどを記述する場所
    return 0;
}
