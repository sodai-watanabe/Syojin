// https://algo-method.com/tasks/363
// 区間スケジューリング問題
// 終了時刻が早いものを優先的に入れると最適解が得られる。
// 予定を入れられる条件は、今まで選んだ予定の中で最も遅い終了時刻(lasttime)より開始時刻(st)が後になっているかどうか。

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<pair<int, int> >s(n);

    for (int i=0; i<n; i++) {
        cin >> s.at(i).second >> s.at(i).first;   //　終了時刻を優先的にsortするので、firstに終了時刻を入れる
    }

    sort(s.begin(), s.end());   //　firstが優先的にsortされる

    int ans = 1;  //　最初の一つ目はまず入れる

    int lasttime = s.at(0).first;    // 今まで選んだ予定の中で、最も遅い終了時刻。初期値は一番初めの予定の終了時刻

    for (int i=1; i<n; i++) {
        int st = s.at(i).second;

        if (lasttime > st) continue; // 今見てる予定の開始時刻がlasttimeよりも前だと、その予定は入れることができないのでスルー。

        ans++;  // 予定が入ったので、1追加。
        lasttime = s.at(i).first;   // 予定を入れたら、lasttimeを更新
    }


    cout << ans << endl;
}