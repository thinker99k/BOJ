#include <iostream>

using namespace std;

int arr[8];

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    bool b;

    // 1. ascending
    b = true;
    for (int i = 0; i < 7; i++) {
        if (arr[i] < arr[i + 1]) {
            continue;
        } else {
            b = false;
            break;
        }
    }
    if (b) {
        cout << "ascending";
        return 0;
    }

    // 2. descending
    b = true;
    for (int i = 0; i < 7; i++) {
        if (arr[i] > arr[i + 1]) {
            continue;
        } else {
            b = false;
            break;
        }
    }
    if (b) {
        cout << "descending";
        return 0;
    }

    // 3. not asc nor dsc
    cout << "mixed";
    return 0;

}