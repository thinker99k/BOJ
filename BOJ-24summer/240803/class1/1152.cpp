#include <iostream>
#include <sstream>

using namespace std;

int ans;

int main() {
    string s, token;
    getline(cin, s);

    istringstream iss(s);

    while(iss >> token){
        //cout << token << '\n';
        ans++;
    }

    cout << ans;
}