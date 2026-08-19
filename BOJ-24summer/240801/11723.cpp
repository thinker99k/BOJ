#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

unordered_map<string, int> fx;

bitset<20> b;
int target;

void hdlr() {
    string command;
    cin >> command;

    switch (fx[command]) {
        case 1: // add
            cin >> target;
            target--;

            b.set(target);
            break;

        case 2: // remove
            cin >> target;
            target--;

            b.reset(target);
            break;

        case 3: // check
            cin >> target;
            target--;

            if (b.test(target)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
            break;

        case 4: // toggle
            cin >> target;
            target--;

            b.flip(target);
            break;

        case 5: // all
            b.set();
            break;

        case 6: // empty
            b.reset();
            break;

        case 7: // show
            cout << b << endl;

        default:;
    }
}

int M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fx["add"] = 1;
    fx["remove"] = 2;
    fx["check"] = 3;
    fx["toggle"] = 4;
    fx["all"] = 5;
    fx["empty"] = 6;
    fx["show"] = 7;

    cin >> M;

    for (int i = 0; i < M; i++) {
        hdlr();
    }
}