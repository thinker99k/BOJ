#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int lrow, lcol;
char arr[101][101];
bool visited[101][101];
bool checked[101][101];
int steps[101][101];

typedef struct {
    int row;
    int col;
} Pos;

bool val(int irow, int icol) {
    // 1. 범위 맞나 검사
    if (irow < 0 || irow >= lrow || icol < 0 || icol >= lcol) {
        return false;
    }

    // 2. 길 맞나 검사
    if (arr[irow][icol] == '0') {
        return false;
    }

    // 3. 방문 했나 검사
    if (visited[irow][icol]) {
        return false;
    }

    // 4. 체크 했나 검사
    if (checked[irow][icol]) {
        return false;
    }

    return true;
}

void show() {
    for (int i = 0; i < lrow; i++) {
        for (int j = 0; j < lcol; j++) {
            printf("%3d", steps[i][j]);
        }
        printf("\n");
    }
    cout << "------------------" << endl;

    for (int i = 0; i < lrow; i++) {
        for (int j = 0; j < lcol; j++) {
            if(visited[i][j]){
                printf(" o ");
            }
            else{
                printf(" x ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void bfs() {
    queue<Pos> q;

    Pos startp = {0, 0};
    q.push(startp);

    int phase = 1;
    int loops = 1;
    while (true) {
        int nextloops = 0;

        cout << "loops: " << loops << endl;
        cout << "phase: " << phase << endl;
        cout << "qsize: " << q.size() << endl;

        for (int i = 0; i < loops; i++) {
            Pos pp = q.front();
            q.pop();
            visited[pp.row][pp.col] = true;
            checked[pp.row][pp.col] = true;

            steps[pp.row][pp.col] = phase;

            cout << "** attempting [" << pp.row << "][" << pp.col << "] **" << endl;


            // 상
            if (val(pp.row - 1, pp.col)) {
                Pos tmp = {pp.row - 1, pp.col};
                q.push(tmp);
                checked[pp.row-1][pp.col] = true;
                nextloops++;
            }

            // 하
            if (val(pp.row + 1, pp.col)) {
                Pos tmp = {pp.row + 1, pp.col};
                q.push(tmp);
                checked[pp.row+1][pp.col] = true;
                nextloops++;
            }

            // 좌
            if (val(pp.row, pp.col - 1)) {
                Pos tmp = {pp.row, pp.col - 1};
                q.push(tmp);
                checked[pp.row][pp.col-1] = true;
                nextloops++;
            }

            // 우
            if (val(pp.row, pp.col + 1)) {
                Pos tmp = {pp.row, pp.col + 1};
                q.push(tmp);
                checked[pp.row][pp.col+1] = true;
                nextloops++;
            }

            show();
        }

        ++phase;
        loops = nextloops;

        if (q.empty()) break;
    }
}


int main() {
    cin >> lrow >> lcol;

    for (int i = 0; i < lrow; i++) {
        cin >> arr[i];
    }

    bfs();

    cout << steps[lrow - 1][lcol - 1];
}