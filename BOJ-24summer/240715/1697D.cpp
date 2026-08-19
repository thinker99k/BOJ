#include <iostream>
#include <queue>

using namespace std;

int n, k;

bool arr[100001];
bool visited[100001];
bool checked[100001];
int steps[100001];

bool val(int pos){
    // 1. 범위 맞나 검사
    if(pos < 0 || pos >= 100001){
        return false;
    }
    // 2. 방문 했나 검사
    if (visited[pos]) {
        return false;
    }
    // 3. 체크 했나 검사
    if (checked[pos]) {
        return false;
    }

    return true;
}

void show(){
    for(int i=0; i<=80; i++){
        printf("%d ", steps[i]);
        if(i%10 == 9){
            printf(" | ");
        }
    }
    printf("\n");
}

int bfs(){
    queue<int> q;

    int start = n;
    q.push(start);

    int phase = 0;
    int loops = 1;

    while (true){
        int nextloops = 0;

        for(int i=0; i<loops; i++){
            int pp = q.front();
            q.pop();
            visited[pp] = true;

            steps[pp] = phase;

            if(pp == k)
                return phase;

            // +1 이동
            if(val(pp+1)){
                q.push(pp+1);
                checked[pp+1] = true;
                nextloops++;
            }

            // -1 이동
            if(val(pp-1)){
                q.push(pp-1);
                checked[pp-1] = true;
                nextloops++;
            }

            // *2 이동
            if(val(pp*2)){
                q.push(pp*2);
                checked[pp*2] = true;
                nextloops++;
            }

            show();
        }
        phase++;
        loops = nextloops;

        if(q.empty()) break;
    }
}

int main(){
    cin >> n >> k;

    int ans = bfs();

    cout << ans;
}