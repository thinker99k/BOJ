#include <iostream>
#include <queue>

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

        cout << "phase " << phase << endl;

        for (int z = 0; z < sz; z++) {
            int p = q.front();
            q.pop();

            steps[p] = phase;

            cout << "approach " << p << endl;
            cout << "(" << p-arr[p] << ", " << p+arr[p] << ")" << endl;
            for (int i = p-arr[p]; i <= p+arr[p]; i++){
                if(val(i)){
                    q.push(i);
                    visited[i] = true;
                    cout << i << " ";
                }
            }
            cout << "queued" << endl;
        }

        phase++;

        cout << endl;

        if(q.empty()) break;
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    bfs();


    for(int i=1; i<=N; i++){
        cout << steps[i];
    }
    cout << endl;


    if(steps[N] == 0){
        cout << -1;
    }
    else{
        cout << steps[N];
    }
}