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
    string str, temp = "";
    cin >> str;
    for(int i = 1; i < str.size()-1; i++) {
        string forth, middle, last;
        for(int j = 1; j < str.size()-i; j++) {
            forth = str.substr(0, i);
            middle = str.substr(i, j);
            last = str.substr(i+j);
            reverse(forth.begin(), forth.end());
            reverse(middle.begin(), middle.end());
            reverse(last.begin(), last.end());
            if(temp.empty() || (forth + middle + last < temp)) temp = forth + middle + last;
        }
    }
    cout << temp << endl;
}