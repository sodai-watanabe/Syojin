// 連想配列
// 今までset<pair<char,int>>のようにしていたところ、unordered_map<char,int>umpで持つ。
// これにより、keyで要素にアクセスできる。indexよりもできることの幅が増える。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        // 順序なし連想配列<文字、その文字の数>
        unordered_map<char,int>ump;

        // 連想配列に文字と、その文字数のペアを追加。ump[key]はkeyの数を表す。
        for (auto i : s) {
            ump[i]++;
        }

        int ans = 0;
        int oddCount = 0;
        for (auto j : ump) {
            if (j.second%2 == 0) {
                ans+=j.second;
            } else {
                ans+=j.second-1;
                oddCount++;
            }
        }
        if (oddCount>0) ans++;
        
        return ans;
    }
};