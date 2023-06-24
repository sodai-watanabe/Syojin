#include <iostream>
using namespace std;

bool is_num(char c){
    return '0' <= c and c <= '9';
}

bool is_upper(char c){
    return 'A' <= c and c <= 'Z';
}


int main(){
    string S;
    cin >> S;

    bool frag = true;
    if(S[1] == '0' || S.size() != 8){
        frag = false;
    }

    if(!is_upper(S[0]) || !is_upper(S[7])){
        frag = false;         
    }
    for(int i=1; i<=6; i++){
       if(!is_num(S[i])){
        frag = false;

       }
    }

    if(frag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}