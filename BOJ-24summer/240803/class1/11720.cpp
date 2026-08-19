#include <iostream>

using namespace std;

int N;
char buf[101];
int ans;

int main(){
    cin >> N >> buf;

    for(int i=0; i<N; i++){
        ans += buf[i]-'0';
    }

    cout << ans;
}