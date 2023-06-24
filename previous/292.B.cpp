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

int main(){
    int N, Q;
    cin >> N >> Q;

    vector<int> red(N+1, 0);
    vector<int> yellow(N+1, 0);

    
     for(int i=0; i<Q; i++){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            yellow.at(x)++;
            if(yellow.at(x) == 2){
                red.at(x) += 1;
                yellow.at(x) = 0;
            }
        }
        if(c == 2){
            red.at(x)++;
        }
        if(c == 3){
            if(red.at(x) != 0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
     }
}