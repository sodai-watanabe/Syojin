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
            // 文字が偶数個の場合は、迷わず全て回文に追加
            // 奇数の場合は、1引いた文字数(偶数個)を回文へ追加。また、奇数個ある文字が何個あるかも管理。
            if (j.second%2 == 0) {
                ans+=j.second;
            } else {
                ans+=j.second-1;
                oddCount++;
            }
        }
        // 残りの使える文字は、奇数個あった文字が一つずつ。全ての文字で一つずつしか無いので、加えられるのは1種類の文字のみ（1文字）。
        // 複数加えると回文にならない
        if (oddCount>0) ans++;
        
        return ans;
    }
};