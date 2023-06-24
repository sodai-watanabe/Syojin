#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;

// string S[400010], T[400010];

int main(){
  int H, W;
  cin >> H >> W;

  vector<string> S(H);
  vector<string> T(H);
  vector<string> tS(W);
  vector<string> tT(W);

  for(int i=0; i<H; i++){
    cin >> S.at(i);
  }
  for(int i=0; i<H; i++){
    cin >> T.at(i);
  }

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
        // tT[j][i] = T[i][j];
        // tS[j][i] = S[i][j];
        tT.at(j).push_back(T.at(i).at(j));
        tS.at(j).push_back(S.at(i).at(j));
    }
  }

  sort(tS.begin(), tS.end());
  sort(tT.begin(), tT.end());

  if(tS == tT){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}