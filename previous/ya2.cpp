#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> Temp(N);
    int hash;

    for (int i=0; i<N; i++){
        string temp;
        cin >> temp;
        Temp.push_back(temp);

        if(temp.at(0) == '#'){
            hash = i;
        }
    }
    cout << hash;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int l;
        cin >> l;

        for(int j=0; j<l; j++){
            string A,B;
            cin >> A >> B;
            if(A == Temp.at(hash)){
                for(int k=0; k<N; k++){
                    if(Temp.at(k)!=A){
                        cout << Temp.at(k) << ' ';
                    }else{
                        cout << B << ' ';
                    }
                    cout << endl;
                }
            }else{
                cout << "Error: Lack of data" << endl;
            }
        }
    }
}