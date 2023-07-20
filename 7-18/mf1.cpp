#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.
  ll N;
  cin >> N;

  vector<ll>A(N);

  for (ll i=0; i<N; i++) {
    cin >> A[i];
  }

  multiset<ll> s;
  ll ans = -1;

  for (ll i=0; i<N; i++) {
    s.insert(A[i]);
    if (s.count(A[i])>1) {
      ans = i+1;
      cout << ans << endl;
      return 0;
    }
  } 

  cout << ans << endl;
  return 0;
}