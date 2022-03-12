#include <iostream>
#include <vector>
#include <map>
#define MAX 1000001
using namespace std;

int N;
int num[MAX];
vector<int> v;
void eratos() {
	num[0] = num[1] = -1;
	for (int i = 2; i < MAX; i++) {
		num[i] = i;
	}
	for (int i = 2; i * i < MAX; i++) {
		if (num[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (num[j] == j)
					num[j] = i;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (num[i] == i)
			v.push_back(i);
	}
}

bool solution(int idx) {
	map<int, bool> m;
	int temp = idx;
	while (1) {
		int result = 0;
		while (temp) {
			result += (temp % 10) * (temp % 10);
			temp /= 10;
		}
		if (result == 1)
			return true;
		if (!m.count(result))
			m[result] = true;
		else
			return false;
		temp = result;
	}
}

int main() {
	cin >> N;
	eratos();
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > N)
			break;
		else
			if (solution(v[i]))
				cout << v[i] << endl;
	}
}