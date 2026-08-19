#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull arr[117];
int n;

int main() {
    for (int i = 1; i < 4; i++) {
        arr[i] = 1;
    }

    cin >> n;

    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 3];

        // cout << "arr[" << i << "] : " << arr[i] << '\n';
    }

    cout << arr[n];
}