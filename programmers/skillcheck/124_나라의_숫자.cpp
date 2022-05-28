#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int tmp = n;
    while(tmp != 0) {
        int remainder = tmp % 3;
        tmp /= 3;
        if(remainder == 0) {
            answer = '4' + answer;
            tmp -= 1;
        } else if(remainder == 1) {
            answer = '1' + answer;
        } else if(remainder == 2) {
            answer = '2' + answer;
        }
    }
    return answer;
}

int main() {
    cout << solution(10) << endl;
}