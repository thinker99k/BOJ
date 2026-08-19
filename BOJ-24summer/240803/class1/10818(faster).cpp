#include <iostream>

using namespace std;

int N, buf;

int main(){
    int max = -1000001;
    int min = 1000001;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> buf;
        if(buf > max){
            max = buf;
        }
        if(buf < min){
            min = buf;
        }
    }

    cout << min << ' ' << max;
}