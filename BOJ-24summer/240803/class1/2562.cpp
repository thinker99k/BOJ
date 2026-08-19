#include <iostream>

using namespace std;

int ans1, ans2; // 최대값, 최대값의 인덱스
int buf;

int main(){
    for(int i=1; i<=9; i++){
        cin >> buf;

        if(buf>ans1){
            ans1 = buf;
            ans2 = i;
        }
    }

    cout << ans1 << '\n' << ans2;
}