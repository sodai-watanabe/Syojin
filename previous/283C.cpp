#include <iostream>
using namespace std;

int main(){
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    
    int count = 0;
    for(int i=0; i<S.size();){
        count++;
        if(S[i] == '0' && i+1<S.size() && S[i+1] == '0'){
            i += 2;
        } else {
            i++;
        }
    }
    cout << count << endl;
}