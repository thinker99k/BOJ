#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int V;

bool visited[100];
vector<int> Vertex[100];

bool ans[100][100];

void dfs(int x) {
    for (int i = 0; i < Vertex[x].size(); i++) { // 한 백터 내 탐색
        if (!visited[Vertex[x][i]]) { // 방문 안했으면
            visited[(Vertex[x][i])] = true;
            dfs(Vertex[x][i]); // 재귀
        }
    }
}

void calc(int x) {
    for (int i=0; i<V; i++){
        ans[x][i] = visited[i];
    }
}


int main(){
    cin >> V;

    vector<int> cango[V];

    // 1. 행렬로 그래프 입력받은 것을 리스트로 저장
    int tmp;
    for(int i=0; i<V;i++){
        for(int j=0; j<V; j++){
            cin >> tmp;

            if(tmp){ // 경로 있으면
                Vertex[i].push_back(j);
            }
        }
    }

    // 2. 정렬
    for(int i=0; i<V; i++){
        sort(Vertex[i].begin(), Vertex[i].end());
    }

    // 3. dfs
    for(int i=0; i<V; i++){
        memset(visited, 0, 100);
        dfs(i);
        calc(i);
    }

    // 4. 출력
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

}