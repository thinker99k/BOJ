#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E, D, s;
vector<int> Vertex[1000001];
bool visited[1000001];


int phase;
vector<int> ans;

void bfs() {
    queue<int> q;

    q.push(s);
    visited[s] = true;

    phase = 0;

    while (true) {
        size_t sz = q.size();

        if (phase == D) {
            for (int i = 0; i < sz; i++) {
                ans.push_back(q.front());
                q.pop();
            }
            break;
        }

        for (int z = 0; z < sz; z++) {
            int p = q.front();
            q.pop();

            int k;
            for (int i = 0; i < Vertex[p].size(); i++) {
                k = Vertex[p][i];
                if (!visited[k]) {
                    q.push(k);
                    visited[k] = true;
                }
            }
        }

        phase++;

        if (q.empty()) break;
    }
}

int main() {
    cin >> V >> E >> D >> s;

    int tmp1, tmp2;
    for (int i = 0; i < E; i++) {
        cin >> tmp1 >> tmp2;
        Vertex[tmp1].push_back(tmp2); // 단방향 간선
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    bfs();

    sort(ans.begin(), ans.end());

    size_t anssz = ans.size();

    if (!anssz) {
        cout << -1;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }
}