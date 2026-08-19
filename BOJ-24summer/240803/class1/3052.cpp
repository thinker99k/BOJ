#include <iostream>
#include <set>

using namespace std;

set<int> s;
int tmp;

int main(){
    for(int i=0; i<10; i++){
        cin >> tmp;
        s.insert(tmp%42);
    }

    cout << s.size();
}