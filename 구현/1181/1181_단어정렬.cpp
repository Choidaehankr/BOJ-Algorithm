#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Comp {
    bool operator() (const string a, const string b) const {
        if(a.size() == b.size()) {
            return a < b;
        } else {
            return a.size() < b.size();
        }
    }
};

int main() {
    int n; 
    cin >> n;
    set<string, Comp> s;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for(set<string>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
}