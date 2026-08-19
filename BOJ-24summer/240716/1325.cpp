#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int V, E, fromV, toV;

vector<int> Vertex[10001];
bool visited[10001];
int pwnd[10001];

void dfs(int x) {
    visited[x] = true;

    for (int i = 0; i < Vertex[x].size(); i++) {
        if (!visited[(Vertex[x])[i]]) {
            dfs((Vertex[x])[i]);
        }
    }
}

int count(int x) {
    int ret = 0;

    for (int i = 1; i <= V; i++) {
        if (visited[i]) {
            ret++;
        }
    }

    pwnd[x] = ret;

    return ret;
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> toV >> fromV;
        Vertex[fromV].push_back(toV); // 간선에 방향성 있음
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    int tmp;
    int max = 0;

    for (int i = 1; i <= V; i++) {
        memset(visited, false, 10001);
        dfs(i);
        tmp = count(i);

        if (tmp > max) {
            max = tmp;
        }
    }

    for (int i = 1; i <= V; i++) {
        if (pwnd[i] == max) {
            printf("%d ", i);
        }
    }
}