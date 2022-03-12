#include <iostream>
#include <string>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++) {
        string str; cin >> str;
        int sum = 0, score = 0;
        for(int j = 0; j < str.size(); j++) {
            if(str[j] == 'O') {
                score+=1;
            } else {
                score = 0;
            }
            sum += score;
        }
        cout << sum << endl;
    }
}