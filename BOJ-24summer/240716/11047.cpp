#include <iostream>

using namespace std;

int n, k;
int main(){
    cin >> n >> k;

    int vals[n];

    for(int i=0; i<n; i++){
        cin >> vals[i];
    }

    int sum = 0;
    int coins = 0;
    int cidx = n-1; // 큰 값부터 더해준다

    while(true){
        // sum과 현재 인덱스의 코인을 더했는데
        if(sum + vals[cidx] > k){ // 값 오버되면
            cidx--;
        }
        else{ // 값 오버 안되면
            sum += vals[cidx];
            coins++;
        }

        if(sum == k) break;
    }

    cout << coins;
}