#include <iostream>
using namespace std;

long long A[100010];

int main(){
    int N;
    long long T;
    cin >> N >> T;

    long long one_cycle = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        one_cycle += A[i];
    }
    long long margin = T % one_cycle;

    long long sum = 0;
    long long ans_time;
    int num ;
    for(int i=1; i<=N; i++){
        sum += A[i-1];
        if(sum > margin){
            num = i;
            ans_time = A[i-1] - (sum - margin);
            break;
        }
    }
    cout << num << ' ' << ans_time << endl;
}