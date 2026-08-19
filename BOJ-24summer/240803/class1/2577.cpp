#include <iostream>

using namespace std;

unsigned long long A, B, C, ABC;

int digits[10];

int main(){
    cin >> A >> B >> C;

    ABC = A*B*C;

    while(ABC){
        digits[ABC%10]++;
        ABC/=10;
    }

    for(int i=0; i<10; i++){
        cout << digits[i] << '\n';
    }
}