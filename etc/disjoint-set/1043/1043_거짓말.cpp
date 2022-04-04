#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool party[51];
vector<vector<int> > v;
queue<int > q;
int n, m, x;

void solution() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == cur) {
					for (int k = 0; k < v[i].size(); k++) {
						if (v[i][k] != cur && !party[i])
							q.push(v[i][k]);
					}
					party[i] = true;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;
	for (int i = 0; i < x; i++) {
		int num; cin >> num;
		q.push(num);
	}
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		vector<int> tmp;
		for (int j = 0; j < num; j++) {
			int p; cin >> p;
			tmp.push_back(p);
		}
		v.push_back(tmp);
	}
	if (x == 0) {
		cout << m << endl;
		return 0;
	}
	solution();
	int result = 0;
	for (int i = 0; i < m; i++) {
		if (!party[i])
			result++;
	}
	cout << result << endl;
}