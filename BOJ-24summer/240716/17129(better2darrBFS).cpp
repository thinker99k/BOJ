#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int lrow, lcol;

char arr[3000][3000];
bool visited[3000][3000];
bool checked[3000][3000];
int steps[3000][3000];

typedef struct {
    int row;
    int col;
} Pos;

bool val(Pos &ip) {
    if (ip.row < 0 || ip.row >= lrow || ip.col < 0 || ip.col >= lcol) {
        return false;
    }

    if (arr[ip.row][ip.col] == '1') {
        return false;
    }

    if (visited[ip.row][ip.col] || checked[ip.row][ip.col]) {
        return false;
    }

    return true;
}

Pos startp;
Pos endp1;
Pos endp2;
Pos endp3;

void bfs() {
    queue<Pos> q;

    q.push(startp);

    int phase = 0;
    int loops = 1;

    while (true) {
        int nextloops = 0;

        for (int i = 0; i < loops; i++) {
            Pos p = q.front();
            q.pop();
            visited[p.row][p.col] = true;
            checked[p.row][p.col] = true;

            steps[p.row][p.col] = phase;

            Pos tmppos[4] = {
                    {p.row - 1, p.col},
                    {p.row + 1, p.col},
                    {p.row,     p.col - 1},
                    {p.row,     p.col + 1}
            };

            for (int j = 0; j < 4; j++) {
                if (val(tmppos[j])) {
                    q.push(tmppos[j]);
                    checked[tmppos[j].row][tmppos[j].col] = true;
                    nextloops++;
                }
            }
        }

        ++phase;
        loops = nextloops;

        if (q.empty()) break;
    }
}

int cmp(const void* i1, const void* i2){
    return *(int*)i1-*(int*)i2;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> lrow >> lcol;

    for (int i = 0; i < lrow; i++) {
        for (int j = 0; j < lcol; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == '2') {
                startp.row = i;
                startp.col = j;
            } else if (arr[i][j] == '3') {
                endp1.row = i;
                endp1.col = j;
            } else if (arr[i][j] == '4') {
                endp2.row = i;
                endp2.col = j;
            } else if (arr[i][j] == '5') {
                endp3.row = i;
                endp3.col = j;
            } else {}
        }
    }

    bfs();
/*
    for (int i = 0; i < lrow; i++) {
        for (int j = 0; j < lcol; j++) {
            cout << steps[i][j];
        }
        cout << endl;
    }
*/
    int distance[3] = {
            steps[endp1.row][endp1.col],
            steps[endp2.row][endp2.col],
            steps[endp3.row][endp3.col]
    };

    qsort(distance, 3, sizeof(int), cmp);

    for(int i=0; i<3; i++){
        if(distance[i] != 0){
            cout << "TAK\n" << distance[i];
            return 0;
        }
    }

    cout << "NIE";
}