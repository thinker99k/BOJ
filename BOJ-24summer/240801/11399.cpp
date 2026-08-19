#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, tmp;
vector<int> v;
int csum1[1001];
int csum2[1001];

int main(){
    cin >> N;
    v.push_back(0);

    for(int i=1; i<=N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int prev1 = 0, prev2 = 0;

    for(int i=1; i<=N; i++){
        prev1 += v[i];
        csum1[i] = prev1;

        prev2 += csum1[i];
        csum2[i] = prev2;
    }

    cout << csum2[N];
}