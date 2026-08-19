#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E, A, B; // A->B 촌수 구해야함
int tmp1, tmp2;

vector<int> Vertex[101];
bool visited[101];
int steps[101];

void bfs() {
    queue<int> q;
    q.push(A);

    int phase = 0;
    visited[A] = true;

    while (true) {
        size_t sz = q.size();

        for (int z = 0; z < sz; z++) {
            int p = q.front();
            q.pop();

            visited[p] = true;
            steps[p] = phase;

            int k;
            for (int i = 0; i < Vertex[p].size(); i++) {
                k = Vertex[p][i];
                if (!visited[k]) {
                    q.push(k);
                    visited[p] = true;
                }
            }
        }

        phase++;

        if (q.empty()) break;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> V;
    cin >> A >> B;
    cin >> E;

    for (int i = 0; i < E; i++) {
        cin >> tmp1 >> tmp2;

        Vertex[tmp1].push_back(tmp2);
        Vertex[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    bfs();

    if(steps[B]){
        cout << steps[B];
    }
    else{
        cout << -1;
    }
}