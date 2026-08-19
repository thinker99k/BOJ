#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[1000][1000];
bool visited[1000][1000];
bool checked[1000][1000];
int steps[1000][1000];

int lrow, lcol;

typedef struct {
    int row;
    int col;
} Pos;

Pos spos;


bool val(Pos &p) {
    if (p.row < 0 || p.row >= lrow || p.col < 0 || p.col >= lcol) {
        return false;
    }

    if (arr[p.row][p.col] == 0) {
        return false;
    }

    if (visited[p.row][p.col]) {
        return false;
    }

    if (checked[p.row][p.col]) {
        return false;
    }

    return true;
}

void bfs() {
    queue<Pos> q;
    q.push(spos);
    checked[spos.row][spos.col] = true;

    int phase = 0;

    while (true) {
        size_t sz = q.size();

        for (int z = 0; z < sz; z++) {
            Pos p = q.front();
            q.pop();

            visited[p.row][p.col] = true;
            steps[p.row][p.col] = phase;

            Pos tmp[4] = {
                    {p.row - 1, p.col},
                    {p.row + 1, p.col},
                    {p.row,     p.col - 1},
                    {p.row,     p.col + 1}
            };

            for (int i = 0; i < 4; i++) {
                if (val(tmp[i])) {
                    q.push(tmp[i]);
                    checked[tmp[i].row][tmp[i].col] = true;
                }
            }
        }

        phase++;

        if (q.empty()) break;
    }
}

int main() {
    memset(steps, -1, sizeof(int)*1000 * 1000);

    cin >> lrow >> lcol;

    int tmp;

    for (int i = 0; i < lrow; i++) {
        for (int j = 0; j < lcol; j++) {
            cin >> tmp;

            if (tmp == 2) {
                spos.row = i;
                spos.col = j;
            }

            if (tmp == 0) {
                steps[i][j] = 0;
            }

            arr[i][j] = tmp;
        }
    }


    bfs();

    for (int i = 0; i < lrow; i++) {
        for (int j = 0; j < lcol; j++) {
            printf("%d ", steps[i][j]);
        }
        printf("\n");
    }
}