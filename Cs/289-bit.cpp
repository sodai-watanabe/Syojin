// bit全探索
// 例えば10このリンゴの選び方は、2^10通り。りんごを取るときは1で取らない時は0に対応させて2進数で表せる。
// 教訓：2^n → (1<<n) 
// 教訓：(i >> j) %2 → 整数iのjbit目が1か0か。 
// 教訓：s[i] |= 1<<a; → 2進数表記s[i]にabit目に1を和集合的に追加。(例：　001 |= 100 → 101)
// 教訓：2進数で 11111→ (1<<5)-1と表せる。(11111=100000-1)


#include <bits/stdc++.h>
using namespace std;

int main () {
    // 1~Nまでの数字が全て入っている選び方を求める。
    // 集合はM個
    int N,M;  
    cin >> N >> M;

    vector<int>s(M);

    for (int i=0; i<M; i++) {
        int c;  // 集合の要素数
        cin >> c;

        for (int j=0; j<c; j++) {
            int a;  // 集合の要素
            cin >> a;
            a--;

            // 2進数表記でabit目を1にする。
            // {1,3,5}ならば、00000→00001→00101→10101
            // 整数 |= (1<<a)　でabit目に和集合的に追加できる。
            s[i] |= 1<<a; 
        }
    }
    
    int ans = 0;  // 1~Nまでの数字が全て入るような選び方。

    // 各集合を選ぶ選ばないの通り数は2^M-1通り。これらをbit全探索。
    // iは2進数表記で、選ぶ(1)選ばない(0)に対応。
    // 0→0,1→1,2→10,3→11,....
    for (int i=0; i< (1<<M); i++) {

        // どの数字(1~N)が含まれているかを表す集合。空集合で初期化。(t=0)
        int t = 0;

        // 一つづつ各集合を見ていく。
        for (int j=0; j<M; j++) {

            // i(選び方)のjbit目が1の時に,j番目の集合の要素を和集合的に追加。
            if ((i >> j) %2) {
                t |= s[j];
            }
        }

        // tが11111...11(全部1)→全種類の数字が入ってる選び方になっている。
        if (t == (1<<N)-1) ans++;
    }

    cout << ans << endl;
}