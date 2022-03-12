#include <iostream>
#include <string>
#include <cstring>

int alpha[26] = {};

using namespace std;

int main() {
    string str;
    cin >> str;
    memset(alpha, -1, sizeof(alpha));
    for(int i = 0; i < str.size(); i++) {
        int num = str[i] - 'a';
        if(alpha[num] == -1) {
            alpha[num] = i;
        }
    }
    for(int i = 0; i < 26; i++) {
        cout << alpha[i] << ' ';
    }
}