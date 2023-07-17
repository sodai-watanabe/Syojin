// https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
// codility array
// 配列要素で、ある値だけ奇数個存在していて、その値を求める。
// ex) [1,1,2,2,3]→3, [3,6,1,3,6]→1
// 当初setで持ったがTEL.
// 方針：配列要素を探索。sort配列でA[i]!=A[i+1]の場合はA[i]は奇数個の要素。

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(),A.end());
    for (int i=0; i<A.size()-1;) {
        if (A[i]!=A[i+1]) {
            return A[i];
        }
        i+=2;
    }
    return A[A.size()-1];
}
