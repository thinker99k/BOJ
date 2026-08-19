#include <iostream>

using namespace std;

int main(){
    unsigned int one = 1;

    for(int i=0; i<10; i++){
        cout << "one: " << one << endl;
        one <<= 1;
    }
}