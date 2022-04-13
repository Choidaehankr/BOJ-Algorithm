#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct comp {
    bool operator()(pair <char, int> a, pair<char, int> b) {
        return a.first > b.first;
    }
};

priority_queue<pair<char, int>, vector<pair<char, int> >, comp> q; 

int main() {
    string str, temp;
    for (int i = 0; i < 50; i++) temp += "z";
    cin >> str;
    // 완전 탐색
    for(int i = 1; i < str.size()-1; i++) {
        string forth, middle, last;
        for(int j = 1; j < str.size()-i; j++) {
            // substr()로 forth, middle, last에 str의 모든 경우의 수를 추출한 후 reverse()로 뒤집음
            forth = str.substr(0, i);  // abcde forth = a
            middle = str.substr(i, j);
            last = str.substr(i+j);
            reverse(forth.begin(), forth.end()); 
            reverse(middle.begin(), middle.end());
            reverse(last.begin(), last.end());
            // 추출한 문자열 중 사전순으로 가장 앞에 나오는 문자를 찾아 temp에 할당
            if((forth + middle + last < temp))  
                temp = forth + middle + last;
        }
    }
    cout << temp << endl;
}