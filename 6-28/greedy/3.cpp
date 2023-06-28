// greedy

#include <bits/stdc++.h>
using namespace std;

int main () {
    int x;
    cin >> x;
    int y[4] = {50,10,5,1};   //具体的な成分が決まってる場合はvectorではなく、y[i]の形で宣言
                              //const vector<int> coins = {50, 10, 5, 1};でもok
    vector<int>A;

    for (int i=0; i<4; i++) {
        int a;
        cin >> a;
        A.push_back(a);      //長さが決まっていないvectorはpush_backで。
    }

    int ans = 0;

    for (int i=0; i<4; i++) {   //greedyに。
        if (x/y[i] >= A.at(i)) {      //改善点：要するに、x/y[i]とA.at(i)の小さい方が、そのコインの枚数として採用されている。
            x -= A.at(i)*(y[i]);      //つまり、条件分岐ではなく count = min(x/y[i], A.at(i)) でいける。
            ans += A.at(i);
        } else {
            int count = x/(y[i]);
            x -= y[i]*count;
            ans += count;
        }

        if (x == 0) break;
    }
    cout << ans << endl;

}