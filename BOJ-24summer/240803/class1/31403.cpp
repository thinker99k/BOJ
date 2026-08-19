#include <iostream>
#include <string>

using namespace std;

int A, B, C;
int ans1, ans2;

int main(){
    cin >> A >> B >> C;

    string sA = to_string(A);
    string sB = to_string(B);
    string sAB = sA+sB;

    ans1 = A+B-C;
    ans2 = stoi(sAB) - C;

    cout << ans1 << '\n' << ans2;
}