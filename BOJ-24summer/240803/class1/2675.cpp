#include <iostream>
#include <cstring>
using namespace std;

int T;
char buf[1001];

int main(){
    cin >> T;
    string ans[T];

    int repeat;

    for(int i=0; i<T; i++){
        memset(buf, 1, 1001);
        cin >> repeat;
        cin >> buf;

        for(int a=0; a<strlen(buf); a++){
            for(int b=0; b<repeat; b++){
                ans[i]+=buf[a];
            }
        }
    }

    for(int i=0; i<T; i++){
        cout << ans[i] << '\n';
    }
}