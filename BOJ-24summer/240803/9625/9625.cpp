#include <iostream>

using namespace std;

int K;
int i1, i2, i3;

int main(){
    cin >> K;

    i1 = 0;
    i2 = 0;
    i3 = 1;

    if(K != 1){
        for(int i=2; i<=K; i++){
            i1 = i2;
            i2 = i3;
            i3 = i1+i2;
        }
    }

    cout << i2 << ' ' << i3;
}