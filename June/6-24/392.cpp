#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sIndex = 0;
        // よくわからないが、stringはsizeでなくlengthのがいいかも
        if (s==t || s.length() == 0) {
            return true;
        }

        for (int i=0; i<t.length(); i++) {
            if (t.at(i) == s.at(sIndex)) {
                sIndex++;
            }
            if (sIndex == s.length()) {
                return true;
            }
        }
        return false;
    }
};