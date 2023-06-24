#include <iostream>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    bool is_ok = true;
    for(int i=0; i<N; i++){
        if(S[i] == '"'){
            if(is_ok){
                is_ok = false;
            } else {
                is_ok = true;
            }
        }

        if(S[i] == ','){
            if(is_ok){
                S[i] = '.';
            }
        }
    }
    cout << S << endl;
}