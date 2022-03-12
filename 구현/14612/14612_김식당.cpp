#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

void print_vector() {
	if (v.size() <= 0) {
		cout << "sleep" << endl;
		return;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << ' ';
		}
		cout << endl;
	}
	
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

void sort_vector() {
	sort(v.begin(), v.end(), cmp);  // 주문 시각을 기준으로 내림차순 정렬
}

void complete_table(int idx) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == idx) {
			v.erase(v.begin()+i);  // 요리가 완성됐다면 벡터에서 해당 인덱스를 제거
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string cmd; cin >> cmd;
		int tableNum, orderTime;
		if (cmd == "order") {
			cin >> tableNum >> orderTime;
			v.push_back({ tableNum, orderTime });
		}
		else if (cmd == "sort") {
			sort_vector();
		}
		else if (cmd == "complete") {
			cin >> tableNum;
			complete_table(tableNum);
		}
		print_vector();  // 각 명령이 끝날 때마다 벡터에 존재하는 테이블들을 출력
	}
}