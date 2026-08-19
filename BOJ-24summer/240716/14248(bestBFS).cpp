#include <iostream>
#include <queue>

using namespace std;

int n, s; // 돌 갯수, 시작점

int arr[100001];
bool visited[100001];

bool val(int x) {
    if (x < 1 || x > n) {
        return false;
    }
    if (visited[x]) {
        return false;
    }
    return true;
}

int vtimes = 0;

void bfs(int s) {
    queue<int> q;

    q.push(s);
    visited[s] = true;
    vtimes++;

    while (true) {
        size_t sz = q.size();

        for (int z = 0; z < sz; z++) {
            int p = q.front();
            q.pop();

            // cout << "visiting " << p << endl;
            // cout << "checking " << p + arr[p] << ", " << p - arr[p] << endl;

            // 우측 이동
            if (val(p + arr[p])) {
                q.push(p + arr[p]);
                visited[p + arr[p]] = true;
                vtimes++;
                // cout << p + arr[p] << "queued" << endl;
            }

            // 좌측 이동
            if (val(p - arr[p])) {
                q.push(p - arr[p]);
                visited[p - arr[p]] = true;
                vtimes++;
                // cout << p - arr[p] << "queued" << endl;
            }
        }

        if (q.empty()) break;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> s;

    bfs(s);

    cout << vtimes;
}