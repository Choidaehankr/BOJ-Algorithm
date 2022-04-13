#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int timeTable[11][101];
int main() {
	int N;
	cin >> N;
	map<string, int> m;
	set<string> s;
	
	int idx = 1;
	for (int i = 0; i < N; i++) {
		string name, place;
		int start, end;
		cin >> name >> place;
		auto it = s.find(name);
		if (it != s.end()) {
			cin >> start >> end;
			continue;
		}
		else {
			s.insert(name);
			m[place] = idx++;
		}
		cin >> start >> end;
		for (int i = start; i < end; i++) {
			timeTable[m[place]][i] += 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << timeTable[i][j] << ' ';
		}
		cout << endl;
	}
}

