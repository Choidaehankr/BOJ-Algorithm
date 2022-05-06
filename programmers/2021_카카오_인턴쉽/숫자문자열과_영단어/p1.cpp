#include <iostream>
#include <string>
#include <map>

using namespace std;

string number[10] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < 10; i++) {
        while(s.find(number[i]) != -1) {
            int idx = s.find(number[i]);
            s.replace(idx, number[i].length(), to_string(i));
            // s.replace(s.find(number[i]), number[i].length(), i);
        }
    }
    answer = stoi(s);
    return answer;
}

int main() {
    string str;
    cin >> str;
    cout << solution(str) << endl;
}