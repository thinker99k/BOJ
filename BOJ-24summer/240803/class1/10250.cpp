#include <iostream>
#include <cstdio>

using namespace std;

int T;
int H, W, N;
int main(){
    cin >> T;

    int ans1[T]; // 층
    int ans2[T]; // 호실

    for(int i=0; i<T; i++){
        cin >> H >> W >> N;

        ans1[i] = N%H; // 층
        ans2[i] = N/H+1; // 호실

        if(!ans1[i]){
            ans1[i] = H;
            ans2[i]--;
        }
    }

    for(int i=0; i<T; i++){
        printf("%d%02d\n", ans1[i], ans2[i]);
    }
}