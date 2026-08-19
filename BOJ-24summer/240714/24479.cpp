#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Vertex[100001]; // 정점 idx 0은 편의상 미사용
bool visited[100001]; // 방문 기록
long long seq[100001];

int V, E, start, fromV, toV; // 정점 갯수, 간선 갯수, 시작점, 임시1, 임시2

int t = 0;

void dfs(int x) {
    visited[x] = true;
    seq[x] = ++t;

    for (int i = 0; i < Vertex[x].size(); i++) { // 한 백터 내 탐색
        if (!visited[(Vertex[x])[i]]) { // 방문 안했으면
            dfs((Vertex[x])[i]); // 재귀
        }
    }
}

int main(void) {
    cin >> V >> E >> start;

    for (int i = 0; i < E; i++) {
        cin >> fromV >> toV;
        Vertex[fromV].push_back(toV);
        Vertex[toV].push_back(fromV);
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    dfs(start);

    for (int i = 1; i <= V; i++) {
        printf("%lld\n", seq[i]);
    }

    return 0;
}