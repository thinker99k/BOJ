#include <iostream>

using namespace std;

string s;
int alphabet[26];

int main(){
    cin >> s;

    fill_n(alphabet, 26, -1);

    for(int i=0; i<s.length(); i++){
        // 아직 발견 못했을 경우만 갱신
        if(alphabet[s[i]-'a'] == -1){
            alphabet[s[i]-'a'] = i;
        }
    }

    for(int i=0; i<26; i++){
        cout << alphabet[i] << ' ';
    }
}