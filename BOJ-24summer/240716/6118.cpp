#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;
int tmp1, tmp2;

vector<int> Vertex[20001];
bool visited[20001];
int steps[20001];

int phase = 0;

void bfs() {
    int start = 1;
    queue<int> q;
    q.push(start);

    visited[start] = true;

    while (true) {
        size_t sz = q.size();

        for (int z = 0; z < sz; z++) {
            int p = q.front();
            q.pop();

            steps[p] = phase;

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

        if (q.empty()) {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> tmp1 >> tmp2;

        Vertex[tmp1].push_back(tmp2);
        Vertex[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    bfs();
    /*
    for(int i=1; i<=V; i++){
        cout << steps[i];
    }
    */

    int maxsteps = phase-1;

    vector<int> maxVec;
    for(int i=1; i<=V; i++){
        if(steps[i] == maxsteps){
            maxVec.push_back(i);
        }
    }

    cout << maxVec.front() << ' ' << phase-1 << ' ' << maxVec.size();

}