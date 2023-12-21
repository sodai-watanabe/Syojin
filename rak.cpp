// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

// 二つの数が、同じ数字を含むかどうかを判定する関数
bool hasSameDigits(int a, int b) {
    // 数字を文字列に変換して、それぞれの数字を集合に格納する
    string strA = to_string(a);
    string strB = to_string(b);

    unordered_set<char> digitsA(strA.begin(), strA.end());
    
    // bの数字とaの数字の集合を比較し、共通の数字があるか判定する
    for (char digit : strB) {
        if (digitsA.find(digit) != digitsA.end()) {
            return false; // 共通の数字が見つかった場合はfalseを返す
        }
    }

    return true; // 共通の数字が見つからなかった場合はtrueを返す
}

int solution(vector<int> &A) {
    // Implement your solution here
    int n = A.size();
    int maxnum = -1;

    // 大きい順にソート
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    // 二つの要素の選び方を全探索
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) continue;          // 同じ要素を見ている時はスキップ。

            // 同じ数字を含まないとき、maxnumを更新。
            if (hasSameDigits(A[i],A[j])) { 
                maxnum = max(maxnum,A[i]+A[j]);
            }
        }
    }

    return maxnum;
}


// 二つの要素の選び方を全探索するとき、2重ループだとO(N^2)なので、最大で10^10回計算してしまう。
// 配列要素をsetで持つことで、重複要素がなくなるので多少は改善できそう。
// 時間切れです。計算量は改善できそうです