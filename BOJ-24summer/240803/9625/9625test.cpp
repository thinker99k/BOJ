#include <iostream>

using namespace std;

string ans;

void fx(int K) {
    int ans1 = 0, ans2 = 0;

    if (K == 1) {
        ans = "B";
    } else { // k > 1
        string s1 = "A";
        string s2 = "B";

        string s3;

        for (int i = 2; i <= K; i++) {
            s3 = s2 + s1;
            s1 = s2;
            s2 = s3;
        }

        ans = s3;
    }

    cout << ans << ": ";

    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] == 'A') {
            ans1++;
        } else {
            ans2++;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    for (int i = 1; i <= 20; i++) {
        fx(i);
    }
}