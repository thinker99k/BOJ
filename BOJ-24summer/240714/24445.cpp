#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> Vertex[100001]; // 정점 idx 0은 편의상 미사용
bool visited[100001]; // 방문 기록
long long seq[100001];

int V, E, start, fromV, toV; // 정점 갯수, 간선 갯수, 시작점, 임시1, 임시2

int t = 0;

void bfs(int sEdge) {
    queue<int> q;
    q.push(sEdge);
    visited[sEdge] = true;
    seq[sEdge] = ++t;

    while (true) {
        int x = q.front();
        q.pop();

        for (int i = Vertex[x].size()-1; i >= 0; i--) { // 한 백터 내 탐색
            if (!visited[(Vertex[x])[i]]) { // 방문 안했으면
                q.push((Vertex[x])[i]); // 큐에 푸시
                visited[(Vertex[x])[i]] = true; // 방문 처리
                seq[(Vertex[x])[i]] = ++t;
            }
        }

        if (q.empty()) break;
    }
}

int main() {
    cin >> V >> E >> start;

    for (int i = 1; i <= E; i++) {
        cin >> fromV >> toV;
        Vertex[fromV].push_back(toV);
        Vertex[toV].push_back(fromV);
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    bfs(start);

    for (int i = 1; i <= V; i++) {
        printf("%lld\n", seq[i]);
    }

    return 0;
}