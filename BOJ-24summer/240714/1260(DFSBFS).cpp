#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> Vertex[10001]; // 정점 idx 0은 편의상 미사용
bool visited[10001]; // 방문 기록

int V, E, start, fromV, toV; // 정점 갯수, 간선 갯수, 시작점, 임시1, 임시2

vector<int> dfsrslt;

void dfs(int x) {
    visited[x] = true;
    dfsrslt.push_back(x);

    for (int i = 0; i < Vertex[x].size(); i++) { // 한 백터 내 탐색
        if (!visited[(Vertex[x])[i]]) { // 방문 안했으면
            dfs((Vertex[x])[i]); // 재귀
        }
    }
}

vector<int> bfsrslt;

void bfs(int sEdge) {
    queue<int> q;
    q.push(sEdge);
    visited[sEdge] = true;

    while (true) {
        int x = q.front();
        q.pop();
        bfsrslt.push_back(x);

        for (int i = 0; i < Vertex[x].size(); i++) { // 한 백터 내 탐색
            if(!visited[ (Vertex[x])[i] ]){ // 방문 안했으면
                q.push( (Vertex[x])[i] ); // 큐에 푸시
                visited[ (Vertex[x])[i] ] = true; // 방문 처리
            }
        }

        if(q.empty()) break;
    }
}


void show() {
    for (int i = 0; i < bfsrslt.size(); i++) {
        cout << dfsrslt[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < dfsrslt.size(); i++) {
        cout << bfsrslt[i] << " ";
    }
}

int main() {
    cin >> V >> E >> start;

    // 1. 입력 후 간선 정보 추가
    for (int i = 1; i <= E; i++) {
        cin >> fromV >> toV;
        Vertex[fromV].push_back(toV);
        Vertex[toV].push_back(fromV);
    }

    // 2. 각 백터 내 정렬
    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    // 3. bfs
    bfs(start);

    // 4. dfs
    memset(visited, false, 10001);
    dfs(start);

    show();

}