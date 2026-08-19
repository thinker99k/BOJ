#include <iostream>

using namespace std;

int N, M;
int ioilen;
int ans;

char arr[2000000];
char sample[2000000];

void myCmp() {
    char *start = arr;
    bool b;

    for (int i = 0; i < M - ioilen + 1; i++) {
        b = true;

        for (int j = 0; j < ioilen; j++) {
            if (start[j] != sample[j]) {
                b = false;
                break;
            }
        }

        if (b) {
            ans++;
        }

        start++;
    }
}

int main() {
    cin >> N;
    cin >> M;
    cin >> arr;

    ioilen = 2 * N + 1;

    for (int i = 0; i < ioilen; i += 2) {
        sample[i] = 'I';
    }

    for (int i = 1; i < ioilen; i += 2) {
        sample[i] = 'O';
    }

    myCmp();

    cout << ans;
}