#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> Vertex[101];
bool visited[101];

int V, E, fromV, toV;

int t = 0;

void bfs(int sEdge) {
    queue<int> q;
    q.push(sEdge);
    visited[sEdge] = true;

    while (true) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < Vertex[x].size(); i++) { // 한 백터 내 탐색
            if (!visited[(Vertex[x])[i]]) { // 방문 안했으면
                q.push((Vertex[x])[i]); // 큐에 푸시
                visited[(Vertex[x])[i]] = true; // 방문 처리
                t++;
            }
        }

        if (q.empty()) break;
    }
}

int main() {
    cin >> V;
    cin >> E;

    for (int i = 1; i <= E; i++) {
        cin >> fromV >> toV;
        Vertex[fromV].push_back(toV);
        Vertex[toV].push_back(fromV);
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    bfs(1);

    cout << t;

    return 0;
}