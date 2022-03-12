#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 51
using namespace std;

int N, M, know_num;
bool fact_man[MAX];
bool fact_party[MAX];
queue<int> q;
vector<vector<int>> party;
vector<int> entry[MAX];
int main() {
	cin >> N >> M;
	cin >> know_num;
	for (int i = 0; i < know_num; i++) {
		int num; cin >> num;
		fact_man[num] = true;
	}
	for (int i = 0; i < M; i++) {
		vector<int> v; 
		party.push_back(v);
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int n; cin >> n;
			party[i].push_back(n);
			entry[n].push_back(i);
			if (fact_man[n]) {
				q.push(i);
			}
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		fact_party[cur] = true;
		for (int i = 0; i < party[cur].size(); i++) {
			int man = party[cur][i];
			for (int j = 0; j < entry[man].size(); j++) {
				int cur_party = entry[man][j];
				if (!fact_party[cur_party]) {
					q.push(cur_party);
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (!fact_party)
			cnt++;
	}
	cout << cnt;
}