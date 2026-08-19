#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> Vertex[101];
bool visited[101];
int steps[101];
int kevin[101];

int V, E, fromV, toV;

void stepsshow() {
    for (int i = 1; i <= V; i++) {
        printf("%3d", steps[i]);
    }
    printf("\n");
}

void bfs(int x) {
    queue<int> q;
    q.push(x);

    int phase = 0;

    while (true) {
        size_t sz = q.size();

        for (int z = 0; z < sz; z++) {
            int pp = q.front();
            q.pop();

            visited[pp] = true;
            steps[pp] = phase;

            for (int i = 0; i < Vertex[pp].size(); i++) {
                if (!visited[Vertex[pp][i]]) {
                    q.push(Vertex[pp][i]);
                    visited[Vertex[pp][i]] = true;
                }
            }
        }

        phase++;

        if (q.empty()) break;
    }
}

int kevincount() {
    int ret = 0;

    for (int i = 1; i <= V; i++) {
        ret += steps[i];
    }

    return ret;
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> fromV >> toV;
        Vertex[fromV].push_back(toV);
        Vertex[toV].push_back(fromV);
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    int min = 1000000000;
    for (int i = 1; i <= V; i++) {
        memset(visited, false, 101);
        memset(steps, 0, 101);
        bfs(i);

        kevin[i] = kevincount();
        if (kevin[i] < min) {
            min = kevin[i];
        }
    }

    for (int i = 1; i <= V; i++) {
        if (kevin[i] == min) {
            cout << i;
            break;
        }
    }
}