#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int i;
    int t;
} it;

int n;

queue<it> q;
bool b[1000001];

bool isvalid(it input){
    // 1. 범위 검사
    if(input.i > n){
        return false;
    }
    else{
        // 2. 중복되지 않게 검사 - 안하면 메모리 초과
        if(b[input.i]){
            return false;
        }
        else{
            return true;
        }
    }
}

int main() {
    cin >> n;

    it start = {1, 0};
    b[start.i] = true;
    it ans;

    q.push(start);

    while (true) {
        it frnt = q.front();
        q.pop();

        if (frnt.i < n) {
            it tmparr[3] = {
                    {frnt.i * 3, frnt.t + 1},
                    {frnt.i * 2, frnt.t + 1},
                    {frnt.i + 1, frnt.t + 1}
            };

            for(int i=0; i<3; i++){
                if(isvalid(tmparr[i])){
                    q.push(tmparr[i]);
                    b[tmparr[i].i] = true;
                }
            }
        } else if (frnt.i == n) {
            ans = frnt;
            break;
        }
    }

    cout << ans.t;
}