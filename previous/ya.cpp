#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        a.at(i) = m;
    }

    string s = " ";
    // cin >> s;
    cout << s;

    vector<string> S;
    vector<string> M;
    vector<string> L;
    vector<string> X;

    // for(int i=0; i<n; i++){
    //     string name;
    //     cin >> name;
    //     int length;
    //     cin >> length;

    //     if(a.at(0) <= length && length < a.at(1)){
    //         S.push_back(name);
    //     } else if (a.at(1) <= length && length < a.at(2)){
    //         M.push_back(name);
    //     } else if (a.at(2) <= length && length < a.at(3)){
    //         L.push_back(name);
    //     } else {
    //         X.push_back(name);
    //     }
    // }

    // cout << "S:" << endl;
    // for(auto n : S){
    //     cout << n << endl;
    // }
    // cout << "M:" << endl;
    // for(auto n : M){
    //     cout << n << endl;
    // }
    // cout << "L:" << endl;
    // for(auto n : L){
    //     cout << n << endl;
    // }
    // cout << "X:" << endl;
    // for(auto n : X){
    //     cout << n << endl;
    // }
}