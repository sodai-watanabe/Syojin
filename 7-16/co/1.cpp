// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
// cofility lesson1
// binary gap
// 与えられた整数が2進数で表される時、1に挟まれている0のうち最大の長さを答える

#include <bits/stdc++.h>
using namespace std;

string toBinary(int n) {   // 整数nを2進数になおす関数
    string r;
    while (n != 0){   // nが0になるまで、2で割り続ける。あまりが1or0でrを追加。
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    reverse(r.begin(),r.end());   // 最後に反転させる
    return r;
}

int solution(int N) {  // codilityではmainではなくsolutionとしないといけない

    string binary = toBinary(N);

    int maxgap = 0;
    int count = 0;

 // 1で囲まれた0の最大の長さを求める。 ex) 100101011100なら2,10001なら3
    bool frag;      
    for (int i=0; i<binary.size(); i++) {
        
        if (binary[i]=='1') {
            frag = true;
            if (count > maxgap) maxgap = count;
            count = 0;
        } else {
            if (frag) count ++;
        }
    }
    // cout << binary << endl;

    // cout << maxgap;

    return maxgap;
}