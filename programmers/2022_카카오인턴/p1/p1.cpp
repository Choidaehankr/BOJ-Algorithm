#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int score[8] = {0, 3, 2, 1, 0, 1, 2, 3};
map<char, int> m;
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i = 0; i < survey.size(); i++) {
        int num = choices[i];  // "5"
        string str = survey[i];  // "AN"
        char agree = str[1], disagree = str[0];
        if(num == 4) continue;
        else if (num >= 1 && num <= 3) {
            m[disagree] += score[num];
        } else if(num >= 5 && num <= 7) {
            m[agree] += score[num];
        }
    }
    if(m['T'] <= m['R']) {
        answer += 'R';
    } else {
        answer += 'T';
    }

    if(m['F'] <= m['C']) {
        answer += 'C';
    } else {
        answer += 'F';
    }

    if(m['M'] <= m['J']) {
        answer += 'J';
    } else {
        answer += 'M';
    }

    if(m['N'] <= m['A']) {
        answer += 'A';
    } else {
        answer += 'N';
    }
    return answer;
}

int main() {
    vector<string> v;
    vector<int> tmp;
    for(int i = 0; i < 5; i++) {
        string str; cin >> str;
        v.push_back(str);
    }
    for(int i = 0; i < 5; i++) {
        int num; cin >> num;
        tmp.push_back(num);
    }
    cout << solution(v, tmp) << endl;
}