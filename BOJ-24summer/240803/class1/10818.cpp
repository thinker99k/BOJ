#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, buf;
vector<int> v;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> buf;
        v.push_back(buf);
    }

    sort(v.begin(), v.end());

    cout << v[0] << ' ' << v[N-1];
}