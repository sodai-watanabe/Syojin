// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0521
// greedy

#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<int>pays;
    // 入力が終わるまで受け取る方法。
    // 入力の個数がわからないときに有効。
    while (1) {
        int p;
        cin >> p;
        if (p == 0) break;
        pays.push_back(p);
    }

    // 不変な値はvectorで定数要素として持っておく。
    // 決して、500の場合、100の場合....と順番に具体的に記述しない。
    vector<int>coins = {500,100,50,10,5,1};

    for (int i=0; i<pays.size(); i++) {
        int ex = 1000 - pays.at(i);
        int count = 0;

        for (auto coin : coins) {
            count += ex/coin;
            ex %= coin;
        }

        cout << count << endl;
    }

}