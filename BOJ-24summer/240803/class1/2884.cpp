#include <iostream>

using namespace std;

int H, M, t, ansH, ansM;

int main(){
    cin >> H >> M;

    t = 60*H + M;
    t -= 45;

    if(t < 0){
        t += 1440;
    }

    ansH = t/60;
    ansM = t%60;

    cout << ansH << ' ' << ansM;
}