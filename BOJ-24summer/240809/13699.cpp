#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull arr[36];
int n;

int main(){
    arr[0] = 1;

    cin >> n;

    ull tmpsum;
    for(int i=1; i<=n; i++){
        tmpsum = 0;

        for(int j=0; j<i; j++){
            tmpsum += arr[j] * arr[i-j-1];
        }

        arr[i] = tmpsum;

        //cout << "arr[" << i << "] : " << arr[i] << '\n';
    }

    cout << arr[n];
}