#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int yCnt = 0, pCnt = 0;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i];
        if(c == 121 || c == 89) yCnt++;
        else if(c == 112 || c == 80) pCnt++;
    }
    if(yCnt == pCnt || (!yCnt && !pCnt)) {
        answer = true;
    } else {
        answer = false;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;

    return answer;
}

int main() {
    string str;
    cin >> str;
    if(solution(str))
        cout << "true" << endl;
    else cout << "false" << endl;
}