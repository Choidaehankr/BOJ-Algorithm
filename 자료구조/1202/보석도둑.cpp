#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// multiset 안쓰는 방법은?

multiset<long long> bags;

int n, k;
long long answer = 0;

vector<pair<long long, long long> > v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int weight, val;
		cin >> weight >> val;
		v.push_back(make_pair(weight, val));
	}
	for (int i = 0; i < k; i++) {
		long long num; cin >> num;
		bags.insert(num);
	}

	// vector를 보석 가격의 내림차순으로 정렬
	sort(v.begin(), v.end(), [](pair<long, long> a, pair<long, long> b) {
		if (a.second == b.second)
			return a.first < b.first;
		else return a.second > b.second;
		});

	// multiset의 lower_bound 사용
	for (int i = 0; i < v.size(); i++) {
		// 보석의 무게를 넣을 수 있는 배낭의 iterator를 반환
		auto it = bags.lower_bound(v[i].first);  // v[i].first = 보석의 무게
		if (it != bags.end()) {
			answer += v[i].second;
			bags.erase(it);
		}
	}
	cout << answer << endl;
}