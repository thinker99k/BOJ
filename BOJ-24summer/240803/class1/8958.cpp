#include <iostream>
#include <cstring>

using namespace std;

int N;
int main(){
    cin >> N;
    char* strings[N];
    int score[N];

    for(int i=0; i<N; i++) {
        strings[i] = new char[81];
        score[i] = 0;

        cin >> strings[i];

        int s = 0;
        for(int j=0; j<strlen(strings[i]); j++){
            if(strings[i][j] == 'O'){
                score[i] += ++s;
            }
            else{
                s = 0;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << score[i] << '\n';
        delete[] strings[i];
    }
}