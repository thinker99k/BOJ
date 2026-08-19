#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull arr[1000001];
int n;

int main() {
    arr[0] = 0;
    arr[1] = 1;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];

        if(arr[i] > 1000000007){
            arr[i] %= 1000000007;
        }

        //cout << "arr[" << i << "] : " << arr[i] << '\n';
    }

    cout << arr[n];
}