#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[1001];
bool visited[1001];
int steps[1001];
int N;

bool val(int x) {
    if (x < 1 || x > N) {
        return false;
    }
    if (visited[x]) {
        return false;
    }

    return true;
}

void bfs() {
    queue<int> q;
    int start = 1;

    q.push(start);
    visited[start] = true;

    int phase = 0;
    steps[start] = phase;

    while (true) {
        size_t sz = q.size();

        for (int z = 0; z < (int)sz; z++) {
            int p = q.front();
            q.pop();

            steps[p] = phase;

            for (int i = p-arr[p]; i <= p+arr[p]; i++){
                if(val(i)){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        phase++;

        if(q.empty()) break;
    }
}

int main() {
    memset(steps, -1, sizeof(int) * 1001);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    bfs();

    if(steps[N] == -1){
        cout << -1;
    }
    else{
        cout << steps[N];
    }
}