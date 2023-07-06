// https://leetcode.com/problems/assign-cookies/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i,j,count;
        i=0;
        j=0;
        count=0;

        // 複数配列で、indexの進み方が異なる場合の実装
        // while文で、条件は最大を超えない。中の条件分岐でindexをそれぞれ進める。
        while (i<g.size() && j<s.size()) {
            if (g.at(i) <= s.at(j)) {
                i++;
                j++;
                count++;
            } else {
                j++;
            }
        }
        return count;
    }
};