#include<bits/stdc++.h>
using namespace std;

int main(){
    int R, C;
    cin >> R >> C;
    vector<string> bomb(R);

    for(int i=0; i<R; i++){
        string b;
        cin >> b;
        bomb.at(i) = b;
    }

    cout << endl;

    vector<vector<bool> > isbomb(R, vector<bool> (C));

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(isdigit(bomb.at(i).at(j))){
                int d = bomb.at(i).at(j) - '0';
                for(int k=0; k<R; k++){
                    for(int m=0; m<C; m++){
                        int dist = abs(i-k) + abs(j-m);
                        if(dist<=d){
                            isbomb.at(k).at(m) = true;
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<R; i++){
        for(int j=0; j<C; j++){
            if(isbomb.at(i).at(j)){
                bomb.at(i).at(j) = '.';
            }
            cout << bomb.at(i).at(j);
        }
        cout << endl;
    }
}